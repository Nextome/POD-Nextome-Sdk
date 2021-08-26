//
//  NMMapPathPoint.h
//  NewMapViewTest
//
//  Created by Francesco Dicarlo on 05/06/14.
//  Copyright (c) 2014 Nextome . All rights reserved.
//
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

@protocol NMMapPathPoint <NSObject>

@property (nonatomic) CGPoint position;

- (instancetype)initWithPoint:(CGPoint)point;

@end
