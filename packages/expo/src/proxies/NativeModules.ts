const MODULES_TO_IGNORE: string[] = [
  'DevLoadingView',
  'EXDevLauncher',
  'EXReactNativeEventEmitter',
  'NativeUnimoduleProxy',
  '$$typeof',
];
const hasWarnedForModule: string[] = [];

function createErrorMessageForStoreClient(moduleName: string) {
  return `Your JavaScript code tried to access a native module, ${moduleName}, that isn't supported in Expo Go.

To continue development with ${moduleName}, you need to create a development build of your app. See https://docs.expo.dev/development/introduction/ for more info.`;
}

function createErrorMessageForDevelopmentBuild(moduleName: string) {
  return `Your JavaScript code tried to access a native module, ${moduleName}, that doesn't exist in this development build.

Make sure you are using the newest available development build of this app and running a compatible version of your JavaScript code. If you've installed a new library recently, you may need to make a new development build.`;
}

export function createProxyForNativeModules(NativeModules: any) {
  if (!__DEV__) {
    return NativeModules;
  }
  return new Proxy(NativeModules, {
    get(target, prop) {
      const value = target[prop];
      if (
        (value === null || value === undefined) &&
        // don't warn on places where the expo package tries to access NativeModules with fallbacks
        !MODULES_TO_IGNORE.includes(prop.toString()) &&
        // only want to show the warning once per module
        !hasWarnedForModule.includes(prop.toString())
      ) {
        hasWarnedForModule.push(prop.toString());

        const isRunningInStoreClient =
          global.ExpoModules?.NativeModulesProxy?.modulesConstants?.ExponentConstants
            ?.executionEnvironment === 'storeClient' ||
          target.NativeUnimoduleProxy?.modulesConstants?.ExponentConstants?.executionEnvironment ===
            'storeClient';
        if (isRunningInStoreClient) {
          console.error(createErrorMessageForStoreClient(prop.toString()));
        } else if (target.EXDevLauncher) {
          console.error(createErrorMessageForDevelopmentBuild(prop.toString()));
        }
      }
      return value;
    },
  });
}
