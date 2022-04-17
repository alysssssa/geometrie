#include <stdio.h>
#include "common.h"
#include "vmath.h"
#include "wdb.h"
#include "raytrace.h"

int main(int argc, const char * argv[]){
    struct rt_wdb *wdbp;
    char new_file_name[50] = "primitive.g";
    if((wdbp=wdb_fopen(new_file_name))==RT_WDB_NULL){
         bu_log("Failed to open output file (%s)\n", new_file_name);
        exit(1);
    }

   /* create a box */
   char *box_name = "b1";
   point_t lo, hi;
   VSETALL(lo, 0.0); /* VSETALL - set all elements of 3D vector to the same scalar value */
   VSETALL(hi, 1000.0);

   /* build the box */
   if(mk_rpp(wdbp, box_name, lo, hi)){
       bu_log("Failed to make a box (%s)\n", box_name);
       exit(1);
   }

   /* create a sphere */
   char *sphere_name = "s1";
   point_t center;
   fastf_t radius;
   VSET(center, 0, 0, 1000);
   radius = 1000.0;

   /* build the sphere */
   if(mk_sph(wdbp, sphere_name, center, radius)){
       bu_log("Failed to make a sphere (%s)\n", sphere_name);
       exit(1);
   }
    
   /* create a torus */
   char *torus_name = "t1";
   point_t center;
   VSET(center, 0, 0, 0);
   vect_t inorm;
   VSET(inorm, 0, 0, 1);
   double r1 = 2000;
   double r2 = 1000;

   /* build the torus */
   if(mk_tor(wdbp, torus_name, center, inorm, r1, r2)){
       bu_log("Failed to make a torus (%s)\n", torus_name);
       exit(1);
   }
    
   /* create a right circular cylinder */
   char *cylinder_name = "c1";
   point_t base;
   VSET(base, 0, 0, 0);
   vect_t height;
   VSET(height, 0, 0, 1000);
   fastf_t radius = 300.0;

   /* build the cylinder */
   if(mk_rcc(wdbp, cylinder_name, base, height, radius)){
       bu_log("Failed to make a cylinder (%s)\n", cylinder_name);
       exit(1);
   }
    
   /* create a cone */
   char *cone_name = "co1";
   point_t base;
   VSET(base, 0, 0, 0);
   vect_t dirv;
   VSET(dirv, 0, 0, 1);
   fastf_t height = 1000.0;
   fastf_t base_radius = 500.0;
   fastf_t nose_radius = 0.0;

   /* build the cone */
   if(mk_cone(wdbp, cone_name, base, dirv, height, base_radius, nose_radius)){
       bu_log("Failed to make a cone (%s)\n", cone_name);
       exit(1);
   }

//
    /* create a prism */
    char *prism_name = "p1";
    point_t vert;
    VSET(vert, 0, 0, 0);
    vect_t xdirv;
    VSET(xdirv, 1, 0, 0);
    vect_t zdirv;
    VSET(zdirv, 0, 0, 1);
    fastf_t xlen = 500.0;
    fastf_t ylen = 700.0;
    fastf_t zlen = 500.0;
    fastf_t x_top_len = 200.0;

    /* build the prism */
    if(mk_wedge(wdbp, prism_name, vert, xdirv, zdirv, xlen, ylen, zlen, x_top_len)){
        bu_log("Failed to make a prism (%s)\n", prism_name);
        exit(1);
    }
    
    printf("Hello, Geometry!\n");
    return 0;
}
