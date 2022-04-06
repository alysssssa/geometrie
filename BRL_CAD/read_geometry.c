#include <stdio.h>
#include "common.h"
#include "vmath.h"
#include "wdb.h"
#include "raytrace.h"

int main(int argc, const char * argv[]){
    struct rt_wdb *wdbp = NULL;
    struct db_i *dbip = DBI_NULL;
    
    /* open existing databases */
    if((dbip = db_open(argv[1], "r+w")) != DBI_NULL){
        /* build a wdbp structure for read/write */
        wdbp = wdb_dbopen(dbip, RT_WDB_TYPE_DB_DISK);
        /* create directory database contents */
        if(db_dirbuild(dbip) < 0){
            bu_log("Error building directory for %s\n", argv[1]);
            exit(-1);
        }else{
            bu_log("Database title is: %s\n", dbip->dbi_title);
        }
    }else{
        bu_exit(1, "Unable to load %s\n", argv[1]);
    }
    
    /* search the directory for a box "b1" */
    struct rt_db_internal ip;
    struct directory *dp;
    RT_DB_INTERNAL_INIT(&ip);
    int cond;
    cond = rt_db_lookup_internal(wdbp->dbip, "b1", &dp, &ip, LOOKUP_NOISY, &rt_uniresource);
    
    /* print the first vertex of the box */
    if (ip.idb_major_type == DB5_MAJORTYPE_BRLCAD /* see db5.h */ && ip.idb_minor_type == ID_ARB8 /* see defines.h */){
        struct rt_arb_internal *arb; /* see geom.h */
        arb = (struct rt_arb_internal *)ip.idb_ptr;
        RT_ARB_CK_MAGIC(arb);
        VPRINT("First Point", arb->pt[0]);
    }

    printf("Hello, Geometry!\n");
    return 0;
}
