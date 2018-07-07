//
//  如遇到问题或有更好方案，请通过以下方式进行联系
//      QQ群：429899752
//      Email：kingsic@126.com
//      GitHub：https://github.com/kingsic/SGPagingView
//
//  SGPageContentCollectionView.h
//  SGPagingViewExample
//
//  Created by kingsic on 16/10/6.
//  Copyright © 2016年 kingsic. All rights reserved.
//

#import <UIKit/UIKit.h>
@class SGPageContentCollectionView;

@protocol SGPageContentCollectionViewDelegate <NSObject>
@optional
/**
 *  联动 SGPageTitleView 的方法
 *
 *  @param pageContentCollectionView      SGPageContentCollectionView
 *  @param progress             SGPageContentCollectionView 内部视图滚动时的偏移量
 *  @param originalIndex        原始视图所在下标
 *  @param targetIndex          目标视图所在下标
 */
- (void)pageContentCollectionView:(SGPageContentCollectionView *)pageContentCollectionView progress:(CGFloat)progress originalIndex:(NSInteger)originalIndex targetIndex:(NSInteger)targetIndex;
/**
 *  获取 SGPageContentCollectionView 当前子控制器的下标值
 *
 *  @param pageContentCollectionView     SGPageContentCollectionView
 *  @param index                         SGPageContentCollectionView 当前子控制器的下标值
 */
- (void)pageContentCollectionView:(SGPageContentCollectionView *)pageContentCollectionView index:(NSInteger)index;
@end

@interface SGPageContentCollectionView : UIView
/**
 *  对象方法创建 SGPageContentCollectionView
 *
 *  @param frame        frame
 *  @param parentVC     当前控制器
 *  @param childVCs     子控制器个数
 */
- (instancetype)initWithFrame:(CGRect)frame parentVC:(UIViewController *)parentVC childVCs:(NSArray *)childVCs;
/**
 *  类方法创建 SGPageContentCollectionView
 *
 *  @param frame        frame
 *  @param parentVC     当前控制器
 *  @param childVCs     子控制器个数
 */
+ (instancetype)pageContentCollectionViewWithFrame:(CGRect)frame parentVC:(UIViewController *)parentVC childVCs:(NSArray *)childVCs;

/** SGPageContentCollectionViewDelegate */
@property (nonatomic, weak) id<SGPageContentCollectionViewDelegate> delegatePageContentCollectionView;
/** 是否需要滚动 SGPageContentCollectionView 默认为 YES；设为 NO 时，不必设置 SGPageContentCollectionView 的代理及代理方法 */
@property (nonatomic, assign) BOOL isScrollEnabled;

/** 给外界提供的方法，根据 SGPageTitleView 标题选中时的下标并显示相应的子控制器 */
- (void)setPageContentCollectionViewCurrentIndex:(NSInteger)currentIndex;

@end