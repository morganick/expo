/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI45_0_0React/ABI45_0_0RCTComponent.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABI45_0_0RCTTextView : UIView

@property (nonatomic, assign) BOOL selectable;

- (void)setTextStorage:(NSTextStorage *)textStorage
          contentFrame:(CGRect)contentFrame
       descendantViews:(NSArray<UIView *> *)descendantViews;

@end

NS_ASSUME_NONNULL_END
