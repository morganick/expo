const NativeModules = require('react-native/Libraries/BatchedBridge/NativeModules');

let proxy = NativeModules;

try {
  const { createProxyForNativeModules } = require('expo/build/proxies/NativeModules');
  proxy = createProxyForNativeModules(NativeModules);
} catch {
  // do nothing, this is expected if no supported version of the expo package is installed
}

module.exports = proxy;
