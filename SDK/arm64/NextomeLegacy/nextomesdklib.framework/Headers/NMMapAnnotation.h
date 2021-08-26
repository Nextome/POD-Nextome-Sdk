//
//  NMMapAnnotation.h
//  NewMapViewTest
//
//  Created by Francesco Dicarlo on 29/05/14.
//  Copyright (c) 2014 Nextome . All rights reserved.
//
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol NMMapAnnotation <NSObject>

@property (nonatomic, readonly) CGPoint coordinate;

@optional

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property(nonatomic) int poiId;



@property (nonatomic, copy) UIView *leftCalloutAccessoryView;
@property (nonatomic, copy) UIView *rightCalloutAccessoryView;

- (void)setCoordinate:(CGPoint)newCoordinate;

@end