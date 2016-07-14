# ASJDropDownMenu

iOS doesn't have a drop down menu by default. Developers are supposed to use the `UIPickerView` for similar functionality. Project design constraints may sometimes however necessitate the use of such a menu. This class is a subclass of `UIView` that has a `UITableView` embedded in it. It provides the functionality needed to show a drop down menu below any `UIView` and is customizable using various properties.

# Installation

CocoaPods is the preferred way to install this library. Add this command to your `Podfile`:

```ruby
pod 'ASJDropDownMenu'
```

# Usage

Creating one is simple. The show method has a completion block which returns the selected item. You may hide the drop down there and then:

```objc
ASJDropDownMenu *dropDownMenu = [[ASJDropDownMenu alloc] initWithView:aView menuItems:anArrayOfASJDropDownMenuItems];
[dropDown showMenuWithCompletion:^(ASJDropDownMenu *dropDownMenu, ASJDropDownMenuItem *menuItem, NSUInteger index)
 {
   [dropDownMenu hideMenu];
 }];
```

Whichever view you provide during instantiation, the dropdown will appear exactly below it. The menu items need to be of type `ASJDropDownMenuItem`s. Constructor methods are provided to generate them. Just attach an array of these to your drop down menu instance.

```objc
ASJDropDownMenuItem *itemWithTitle = [ASJDropDownMenuItem itemWithTitle:@"a title"];
ASJDropDownMenuItem *anotherItemWithTitle = [ASJDropDownMenuItem itemWithTitle:@"another title"];
anInstanceOfDropDownMenu.menuItems = @[itemWithTitle, anotherItemWithTitle];
```

```objc
ASJDropDownMenuItem *itemWithSubtitle = [ASJDropDownMenuItem itemWithTitle:@"a title" subtitle:@"a subtitle" image:anImage];
ASJDropDownMenuItem *anotherItemWithSubtitle = [ASJDropDownMenuItem itemWithTitle:@"another title" subtitle:@"another subtitle" image:anotherImage];
anInstanceOfDropDownMenu.menuItems = @[itemWithSubtitle, anotherItemWithSubitle];
```

![alt tag](Screenshot.png)

### Customization

There are a few properties that you can use to customize the drop down menu:

```objc
@property (nullable, strong, nonatomic) UIColor *menuColor;
@property (nullable, strong, nonatomic) UIColor *itemColor;
@property (nullable, strong, nonatomic) UIFont *itemFont;
@property (assign, nonatomic) CGFloat itemHeight;
@property (assign, nonatomic) BOOL hidesOnSelection;
@property (assign, nonatomic) ASJDropDownMenuScrollIndicatorStyle indicatorStyle;
```

The indicator style uses the default `UIScrollView` indicator styles; default, black and white. If you want to set a custom color to the scroll indicator, you can look up [ASJColoredScrollIndicators](https://github.com/sudeepjaiswal/ASJColoredScrollIndicators).

# To-do

- Animation to open and close.
- ~~Provision to add images.~~
- ~~Provision to close on item selection.~~
- Option to open the drop down in up or down direction.
- Move the screen to accomodate the drawer when keyboard shows.

# License

`ASJDropDownMenu` is available under the MIT license. See the LICENSE file for more info.
