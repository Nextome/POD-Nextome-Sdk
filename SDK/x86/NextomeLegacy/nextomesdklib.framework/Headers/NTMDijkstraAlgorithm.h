//
//  NTMDijkstraAlgorithm.h
//  nextomesdk
//
//  Created by Francesco Dicarlo on 27/01/16.
//  Copyright © 2016 Next To Me. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NTMVertex.h"
#import "NTMEdge.h"

@interface NTMDijkstraAlgorithm : NSObject

@property(nonatomic,strong) NSArray *nodes;
@property(nonatomic,strong) NSArray *edges;
@property(nonatomic,strong) NSMutableSet *settledNodes;
@property(nonatomic,strong) NSMutableSet *unsettledNodes;
@property(nonatomic,strong) NSMutableDictionary *predecessors;
@property(nonatomic,strong) NSMutableDictionary *distance;


-(void)execute:(NTMVertex*) source;
-(NSMutableArray*) getPath:(NTMVertex*) target;


@end
