//
//  NMMapPolyline.h
//  NewMapViewTest
//
//  Created by Francesco Dicarlo on 05/06/14.
//  Copyright (c) 2014 Nextome . All rights reserved.
//
#import "NMMapPathPoint.h"
#import "NMMapShape.h"

@interface NMMapPath : NMMapShape

- (instancetype)initWithPoints:(NSArray*)points;

- (void)addPoint:(id <NMMapPathPoint>)point;
- (void)removePointAtIndex:(NSInteger)index;

+ (instancetype)pathWithPoints:(NSArray*)points;

- (NSArray*)path;
@end
