/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#include <ABI45_0_0React/ABI45_0_0renderer/attributedstring/AttributedString.h>
#include <ABI45_0_0React/ABI45_0_0renderer/attributedstring/AttributedStringBox.h>
#include <ABI45_0_0React/ABI45_0_0renderer/attributedstring/TextAttributes.h>

NS_ASSUME_NONNULL_BEGIN

NSString *const ABI45_0_0RCTAttributedStringIsHighlightedAttributeName = @"IsHighlighted";
NSString *const ABI45_0_0RCTAttributedStringEventEmitterKey = @"EventEmitter";
NSString *const ABI45_0_0RCTTextAttributesAccessibilityRoleAttributeName = @"AccessibilityRole";

/*
 * Creates `NSTextAttributes` from given `ABI45_0_0facebook::ABI45_0_0React::TextAttributes`
 */
NSDictionary<NSAttributedStringKey, id> *ABI45_0_0RCTNSTextAttributesFromTextAttributes(
    ABI45_0_0facebook::ABI45_0_0React::TextAttributes const &textAttributes);

/*
 * Conversions amond `NSAttributedString`, `AttributedString` and `AttributedStringBox`.
 */
NSAttributedString *ABI45_0_0RCTNSAttributedStringFromAttributedString(
    ABI45_0_0facebook::ABI45_0_0React::AttributedString const &attributedString);

NSAttributedString *ABI45_0_0RCTNSAttributedStringFromAttributedStringBox(
    ABI45_0_0facebook::ABI45_0_0React::AttributedStringBox const &attributedStringBox);

ABI45_0_0facebook::ABI45_0_0React::AttributedStringBox ABI45_0_0RCTAttributedStringBoxFromNSAttributedString(
    NSAttributedString *nsAttributedString);

NSString *ABI45_0_0RCTNSStringFromStringApplyingTextTransform(NSString *string, ABI45_0_0facebook::ABI45_0_0React::TextTransform textTransform);

@interface ABI45_0_0RCTWeakEventEmitterWrapper : NSObject
@property (nonatomic, assign) ABI45_0_0facebook::ABI45_0_0React::SharedEventEmitter eventEmitter;
@end

NS_ASSUME_NONNULL_END
