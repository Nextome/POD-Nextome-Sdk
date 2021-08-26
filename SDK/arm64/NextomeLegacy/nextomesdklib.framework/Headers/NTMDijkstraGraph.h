//
//  NTMDijkstraGraph.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 27/01/16.
//  Copyright © 2016 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTMVertex.h"
#import "NTMEdge.h"
#import "NTMDijkstraAlgorithm.h"

@interface NTMDijkstraGraph : NSObject

@property(nonatomic,strong) NSArray *nodes;
@property(nonatomic,strong) NSArray *edges;

-(NSArray *) getPath:(int) sourceX andSourceY:(int) sourceY andDestinationX:(int) destinationX andDestinationY:(int) destinationY andSourceMap:(int) sourceMap andDestinationMap:(int) destinationMap;

@end
