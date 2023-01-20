//
// This file is part of the Tioga software library
//
// Tioga  is a tool for overset grid assembly on parallel distributed systems
// Copyright (C) 2015 Jay Sitaraman
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef TIOGA_UTILS_H
#define TIOGA_UTILS_H

/* header files */
#include "tioga.h"

void findOBB(double *x, double xc[3], double dxc[3], double vec[3][3],
             int nnodes);
int checkHoleMap(double *x, int *nx, int *sam, double *extents);
int checkAdaptiveHoleMap(double *xpt,ADAPTIVE_HOLEMAP *AHM);
void fillHoleMap(int *holeMap, int ix[3], int isym);
void octant_children(uint8_t children_level,uint32_t idx,
                     octant_full_t * q,
                     octant_full_t * c0, octant_full_t * c1,
                     octant_full_t * c2, octant_full_t * c3,
                     octant_full_t * c4, octant_full_t * c5,
                     octant_full_t * c6, octant_full_t * c7);
void octant_children_neighbors(const octant_full_t * q,
                               octant_full_t *c0, octant_full_t *c1,
                               octant_full_t *c2, octant_full_t *c3,
                               octant_full_t *c4, octant_full_t *c5,
                               octant_full_t *c6, octant_full_t *c7);
void floodfill_level(level_octant_t *level);
int obbIntersectCheck(double vA[3][3], double xA[3], double dxA[3],
                      double vB[3][3], double xB[3], double dxB[3]);
void getobbcoords(double xc[3], double dxc[3], double vec[3][3],
                  double xv[8][3]);
void transform2OBB(double xv[3], double xc[3], double vec[3][3], double xd[3]);
void writebbox(OBB *obb, int bid);
void writebboxdiv(OBB *obb, int bid);
void writePoints(double *x, int nsearch, int bid);
void uniquenodes(double *x, int *meshtag, double *rtag, int *itag, int *nn);
void uniqNodesTree(double *coord, int *itag, double *rtag, int *meshtag,
                   int *elementsAvailable, int ndim, int nav);
void uniquenodes_octree(double *x, int *meshtag, double *rtag, int *itag,
                        int *nn);

void qcoord_to_vertex(qcoord_t x,qcoord_t y,qcoord_t z,double *vertices,double vxyz[3]);
char checkFaceBoundaryNodes(int *nodes,const char *bcnodeflag,const int numfaceverts,const int *faceConn,const char *duplicatenodeflag);
int triBoxOverlap(double boxcenter[3],double boxhalfsize[3],double *pt1,double *pt2,double *pt3);

#endif /* TIOGA_UTILS_H */