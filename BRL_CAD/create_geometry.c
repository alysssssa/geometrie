#include <stdio.h>
#include "common.h"
#include "vmath.h"
#include "wdb.h"
#include "raytrace.h"

int main(int argc, const char * argv[]){
    struct rt_wdb *wdbp;
    char new_file_name[50] = "output.g";
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
    
    /* build a combination */
    struct bu_list head;
    struct wmember *wmp;
    
    /* initialize the list of members for this combination */
    BU_LIST_INIT(&head);
    
    /* add the first member - sphere - (use the UNION operator here) */
    if((wmp=mk_addmember("s1", &head, NULL, WMOP_UNION)) == WMEMBER_NULL){
        bu_log("Failed to add member(s1)\n");
        exit(1);
    }
    
    /* subtract the second member - box */
    if((wmp=mk_addmember("b1", &head, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(b1)\n");
        exit(1);
    }
    
    /* build the region */
    if( mk_comb(wdbp, "region1", &head, 1, NULL, NULL, NULL, 1000, 0, 1, 100, 0, 0, 0)){
        bu_log("Error building region\n");
        exit(1);
    }
    
    printf("Hello, Geometry!\n");
    return 0;
}
