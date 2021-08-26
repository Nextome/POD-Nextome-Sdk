//
//  TestPoint.h
//  NewMapViewTest
//
//  Created by Francesco Dicarlo on 05/06/14.
//  Copyright (c) 2014 Nextome . All rights reserved.
//
#import "NMMapPathPoint.h"
#import <Foundation/Foundation.h>

@interface NMMapPathDefaultPoint : NSObject <NMMapPathPoint>
- (instancetype)initWithPoint:(CGPoint)point;
@end
