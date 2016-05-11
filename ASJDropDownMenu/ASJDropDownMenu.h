// ASJDropDownMenu.h
//
// Copyright (c) 2014 Sudeep Jaiswal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

@import UIKit;

@class ASJDropDownMenu;
@class ASJDropDownMenuItem;

NS_ASSUME_NONNULL_BEGIN

typedef void (^ASJDropDownMenuCompletionBlock)(ASJDropDownMenu *dropDownMenu, ASJDropDownMenuItem *menuItem, NSUInteger index);

typedef NS_ENUM(NSUInteger, ASJDropDownMenuScrollIndicatorStyle) {
  ASJDropDownMenuScrollIndicatorStyleDefault,
  ASJDropDownMenuScrollIndicatorStyleBlack,
  ASJDropDownMenuScrollIndicatorStyleWhite
};

@interface ASJDropDownMenu : UIView

/**
 *  Background color of the drop down menu
 */
@property (nullable, strong, nonatomic) UIColor *menuColor;

/**
 *  Text color of the menu items
 */
@property (nullable, strong, nonatomic) UIColor *itemColor;

/**
 *  Font of the menu items
 */
@property (nullable, strong, nonatomic) UIFont *itemFont;

/**
 *  Height of individual menu items
 */
@property (assign, nonatomic) CGFloat itemHeight;

/**
 *  Type of scroll indicator for the scroll view
 */
@property (assign, nonatomic) ASJDropDownMenuScrollIndicatorStyle indicatorStyle;

/**
 *  An array of strings to show in the drop down menu
 */
@property (copy, nonatomic) NSArray<ASJDropDownMenuItem *> *menuItems;

/**
 *  Use the designated initializer to construct a drop down menu
 *
 *  @param view The view under which to show the drop down
 *
 *  @return Returns an instance of ASJDropDownMenu
 */
- (instancetype)initWithView:(__kindof UIView *)view NS_DESIGNATED_INITIALIZER;

/**
 *  Show the drop down menu under the specified text field
 *
 *  @param callback Returns the drop down menu object, the selection and the index at which it belongs in the array
 */
- (void)showMenuWithCompletion:(nullable ASJDropDownMenuCompletionBlock)callback;

/**
 *  Hides the drop down from the screen
 */
- (void)hideMenu;

@end

@interface ASJDropDownMenuItem : NSObject

/**
 *  Main text of the menu item.
 */
@property (copy, nonatomic) NSString *title;

/**
 *  Accompanying text below the main text. Optional.
 */
@property (nullable, copy, nonatomic) NSString *subtitle;

/**
 *  Convenience constructors. Will only show the main text.
 */
+ (ASJDropDownMenuItem *)itemWithTitle:(NSString *)title;

/**
 *  Convenience constructor. 'subtitle' can be nil.
 */
+ (ASJDropDownMenuItem *)itemWithTitle:(NSString *)title subtitle:(nullable NSString *)subtitle;

@end

NS_ASSUME_NONNULL_END
