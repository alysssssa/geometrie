#include <stdio.h>
#include "common.h"
#include "vmath.h"
#include "wdb.h"
#include "raytrace.h"

int main(int argc, const char * argv[]){
    struct rt_wdb *wdbp;
    char new_file_name[50] = "bathtub.g";
    if((wdbp=wdb_fopen(new_file_name))==RT_WDB_NULL){
         bu_log("Failed to open output file (%s)\n", new_file_name);
        exit(1);
    }

    /* create the big box */
    char *box_name = "b0";
    point_t lo, hi;
    VSETALL(lo, -100.0);
    VSET(hi, 1900, 700, 700);

    if(mk_rpp(wdbp, box_name, lo, hi)){
        bu_log("Failed to make a box (%s)\n", box_name);
        exit(1);
    }
    
    /* create lower left corner */
    char *box_name_1 = "b1";
    point_t lo_1, hi_1;
    VSETALL(lo_1, 0.0);
    VSET(hi_1, 200, 200, 700);
    
    if(mk_rpp(wdbp, box_name_1, lo_1, hi_1)){
        bu_log("Failed to make a box (%s)\n", box_name_1);
        exit(1);
    }
    
    char *cylinder_name_1 = "c1";
    point_t base_1;
    VSET(base_1, 200, 200, 0);
    vect_t height_1;
    VSET(height_1, 0, 0, 700);
    fastf_t radius_1 = 200.0;

    if(mk_rcc(wdbp, cylinder_name_1, base_1, height_1, radius_1)){
        bu_log("Failed to make a cylinder (%s)\n", cylinder_name_1);
        exit(1);
    }
    
    /* build lower left corner */
    struct bu_list head;
    struct wmember *wmp;
    BU_LIST_INIT(&head);
    
    if((wmp=mk_addmember("b1", &head, NULL, WMOP_UNION)) == WMEMBER_NULL){
        bu_log("Failed to add member(b1)\n");
        exit(1);
    }
    
    if((wmp=mk_addmember("c1", &head, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(c1)\n");
        exit(1);
    }
    
    if( mk_comb(wdbp, "corner1", &head, 1, NULL, NULL, NULL, 1000, 0, 1, 100, 0, 0, 0)){
        bu_log("Error building corner1\n");
        exit(1);
    }
    
    /* create upper left corner */
    char *box_name_2 = "b2";
    point_t lo_2, hi_2;
    VSET(lo_2, 0.0, 400, 0);
    VSET(hi_2, 200, 600, 700);
    
    if(mk_rpp(wdbp, box_name_2, lo_2, hi_2)){
        bu_log("Failed to make a box (%s)\n", box_name_2);
        exit(1);
    }
    
    char *cylinder_name_2 = "c2";
    point_t base_2;
    VSET(base_2, 200, 400, 0);
    vect_t height_2;
    VSET(height_2, 0, 0, 700);
    fastf_t radius_2 = 200.0;

    if(mk_rcc(wdbp, cylinder_name_2, base_2, height_2, radius_2)){
        bu_log("Failed to make a cylinder (%s)\n", cylinder_name_2);
        exit(1);
    }
    
    /* build upper left corner */
    struct bu_list head_2;
    struct wmember *wmp_2;
    BU_LIST_INIT(&head_2);
    
    if((wmp_2=mk_addmember("b2", &head_2, NULL, WMOP_UNION)) == WMEMBER_NULL){
        bu_log("Failed to add member(b2)\n");
        exit(1);
    }
    
    if((wmp_2=mk_addmember("c2", &head_2, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(c2)\n");
        exit(1);
    }
    
    if( mk_comb(wdbp, "corner2", &head_2, 1, NULL, NULL, NULL, 1000, 0, 1, 100, 0, 0, 0)){
        bu_log("Error building corner2\n");
        exit(1);
    }
    
    /* create upper right corner */
    char *box_name_3 = "b3";
    point_t lo_3, hi_3;
    VSET(lo_3, 1600, 400, 0);
    VSET(hi_3, 1800, 600, 700);
    
    if(mk_rpp(wdbp, box_name_3, lo_3, hi_3)){
        bu_log("Failed to make a box (%s)\n", box_name_3);
        exit(1);
    }
    
    char *cylinder_name_3 = "c3";
    point_t base_3;
    VSET(base_3, 1600, 400, 0);
    vect_t height_3;
    VSET(height_3, 0, 0, 700);
    fastf_t radius_3 = 200.0;

    if(mk_rcc(wdbp, cylinder_name_3, base_3, height_3, radius_3)){
        bu_log("Failed to make a cylinder (%s)\n", cylinder_name_3);
        exit(1);
    }
    
    /* build upper right corner */
    struct bu_list head_3;
    struct wmember *wmp_3;
    BU_LIST_INIT(&head_3);
    
    if((wmp_3=mk_addmember("b3", &head_3, NULL, WMOP_UNION)) == WMEMBER_NULL){
        bu_log("Failed to add member(b3)\n");
        exit(1);
    }
    
    if((wmp_3=mk_addmember("c3", &head_3, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(c3)\n");
        exit(1);
    }
    
    if( mk_comb(wdbp, "corner3", &head_3, 1, NULL, NULL, NULL, 1000, 0, 1, 100, 0, 0, 0)){
        bu_log("Error building corner3\n");
        exit(1);
    }
    
    /* create lower right corner */
    char *box_name_4 = "b4";
    point_t lo_4, hi_4;
    VSET(lo_4, 1600, 0, 0);
    VSET(hi_4, 1800, 200, 700);
    
    if(mk_rpp(wdbp, box_name_4, lo_4, hi_4)){
        bu_log("Failed to make a box (%s)\n", box_name_4);
        exit(1);
    }
    
    char *cylinder_name_4 = "c4";
    point_t base_4;
    VSET(base_4, 1600, 200, 0);
    vect_t height_4;
    VSET(height_4, 0, 0, 700);
    fastf_t radius_4 = 200.0;

    if(mk_rcc(wdbp, cylinder_name_4, base_4, height_4, radius_4)){
        bu_log("Failed to make a cylinder (%s)\n", cylinder_name_4);
        exit(1);
    }
    
    /* build lower left corner */
    struct bu_list head_4;
    struct wmember *wmp_4;
    BU_LIST_INIT(&head_4);
    
    if((wmp_4=mk_addmember("b4", &head_4, NULL, WMOP_UNION)) == WMEMBER_NULL){
        bu_log("Failed to add member(b4)\n");
        exit(1);
    }
    
    if((wmp_4=mk_addmember("c4", &head_4, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(c4)\n");
        exit(1);
    }
    
    if( mk_comb(wdbp, "corner4", &head_4, 1, NULL, NULL, NULL, 1000, 0, 1, 100, 0, 0, 0)){
        bu_log("Error building corner4\n");
        exit(1);
    }
    
    /* create the void */
    char *box_name_5 = "b5";
    point_t lo_5, hi_5;
    VSET(lo_5, 0, 0, 0);
    VSET(hi_5, 1800, 600, 700);
    
    if(mk_rpp(wdbp, box_name_5, lo_5, hi_5)){
        bu_log("Failed to make a box (%s)\n", box_name_5);
        exit(1);
    }
    
    /* build the void */
    struct bu_list head_5;
    struct wmember *wmp_5;
    BU_LIST_INIT(&head_5);
    
    if((wmp_5=mk_addmember("b5", &head_5, NULL, WMOP_UNION)) == WMEMBER_NULL){
        bu_log("Failed to add member(b5)\n");
        exit(1);
    }
    
    if((wmp_5=mk_addmember("corner1", &head_5, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(corner1)\n");
        exit(1);
    }
    
    if((wmp_5=mk_addmember("corner2", &head_5, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(corner2)\n");
        exit(1);
    }
    
    if((wmp_5=mk_addmember("corner3", &head_5, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(corner3)\n");
        exit(1);
    }
    
    if((wmp_5=mk_addmember("corner4", &head_5, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(ccorner4)\n");
        exit(1);
    }
    
    if( mk_comb(wdbp, "void", &head_5, 1, NULL, NULL, NULL, 1000, 0, 1, 100, 0, 0, 0)){
        bu_log("Error building void\n");
        exit(1);
    }

    /* build the bathtub */
    struct bu_list head_6;
    struct wmember *wmp_6;
    BU_LIST_INIT(&head_6);
    
    if((wmp_6=mk_addmember("b0", &head_6, NULL, WMOP_UNION)) == WMEMBER_NULL){
        bu_log("Failed to add member(b0)\n");
        exit(1);
    }
    
    if((wmp_6=mk_addmember("void", &head_6, NULL, WMOP_SUBTRACT)) == WMEMBER_NULL){
        bu_log("Failed to add member(void)\n");
        exit(1);
    }
    
    if( mk_comb(wdbp, "bathtub", &head_6, 1, NULL, NULL, NULL, 1000, 0, 1, 100, 0, 0, 0)){
        bu_log("Error building bathtub\n");
        exit(1);
    }
    
    printf("Hello, Bathtub!!!\n");
    return 0;
}
