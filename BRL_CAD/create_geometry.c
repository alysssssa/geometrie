#include <stdio.h>
#include "common.h"
#include "vmath.h"
#include "wdb.h"
#include "raytrace.h"

int main(int argc, const char * argv[]){
    struct rt_wdb *wdbp;
    char new_file_name[50] = "geom.g";
    if((wdbp=wdb_fopen(new_file_name))==RT_WDB_NULL){
         bu_log("Failed to open output file (%s)\n", new_file_name);
        exit(1);
    }

    /* create a box */
    char *box_name = "b1";
    point_t lo, hi;
    VSETALL(lo, 0.0); /* VSETALL - set all elements of 3D vector to the same scalar value */
    VSETALL(hi, 2.0);
    
    /* build the box */
    if(mk_rpp(wdbp, box_name, lo, hi)){
        bu_log("Failed to make a sphere (%s)\n", box_name);
        exit(1);
    }
    
    /* create a sphere */
    char *sphere_name = "s1";
    point_t center;
    fastf_t radius;
    VSET(center, 2, 2, 2);
    radius = 1.0;
    
    /* build the sphere */
    if(mk_sph(wdbp, sphere_name, center, radius)){
        bu_log("Failed to make a sphere (%s)\n", sphere_name);
        exit(1);
    }
    
    printf("Hello, Geometry!\n");
    return 0;
}
