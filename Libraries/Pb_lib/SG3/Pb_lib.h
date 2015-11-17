/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _PB_LIB_
#define _PB_LIB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Datatypes and datatypes of function blocks */
typedef struct PBInternalStruct
{	unsigned char init;
	unsigned char state;
	unsigned long vbli_ptr;
	unsigned short kr_anz;
	unsigned short kr;
	unsigned short kr_merker;
	unsigned long apb_ptr;
	unsigned long resp_adr;
	unsigned long p_out_ptr;
	unsigned long time;
	unsigned char nurinit;
	unsigned char sapli_nr;
} PBInternalStruct;

typedef struct PBreadI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned short subindex;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBreadI_typ;

typedef struct PBreadN
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned char spec_id;
	unsigned long name;
	unsigned short subindex;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBreadN_typ;

typedef struct PBwriteI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned short subindex;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBwriteI_typ;

typedef struct PBwriteN
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned char spec_id;
	unsigned long name;
	unsigned short subindex;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBwriteN_typ;

typedef struct PBwriteP
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long phy_adr;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long phy_adr_merker;
	unsigned long data_ptr;
	unsigned short restlen;
	unsigned char paket_len;
	unsigned char req_len;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBwriteP_typ;

typedef struct PBreadP
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long phy_adr;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long phy_adr_merker;
	unsigned long data_ptr;
	unsigned short restlen;
	unsigned char paket_len;
	unsigned char req_len;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBreadP_typ;

typedef struct PBautoKR
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned char onoff;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBautoKR_typ;

typedef struct PBinfoKR
{
	/* VAR_INPUT (analog) */
	unsigned long name;
	unsigned long info_ptr;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned short kr;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PBinfoKR_typ;

typedef struct PBrdDVL
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long liste;
	unsigned char anzahl;
	unsigned char ind_phy;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned short rdlen;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBrdDVL_typ;

typedef struct PBreadX
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short offset;
	unsigned long name;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long phy_adr;
	unsigned long phy_adr_merker;
	unsigned long data_ptr;
	unsigned short restlen;
	unsigned char paket_len;
	unsigned char req_len;
	unsigned char name_merker;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBreadX_typ;

typedef struct PBrec
{
	/* VAR_INPUT (analog) */
	unsigned long par_ptr;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned long dat_ptr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBrec_typ;

typedef struct PBevnotI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned char ev_nr;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBevnotI_typ;

typedef struct PBdelVLN
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long name;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBdelVLN_typ;

typedef struct PBrdDPR
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short offset;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long phy_adr_merker;
	unsigned long data_ptr;
	unsigned short restlen;
	unsigned char paket_len;
	unsigned char req_len;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBrdDPR_typ;

typedef struct PBinit
{
	/* VAR_INPUT (analog) */
	unsigned short srv_cnt;
	unsigned long memsize;
	unsigned long par_ptr;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned long memadr;
	/* VAR (analog) */
	unsigned char init;
	unsigned char nurinit;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PBinit_typ;

typedef struct PBwriteX
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short offset;
	unsigned long name;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long phy_adr;
	unsigned long phy_adr_merker;
	unsigned long data_ptr;
	unsigned short restlen;
	unsigned char paket_len;
	unsigned char req_len;
	unsigned char name_merker;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBwriteX_typ;

typedef struct PBdlI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned long modptr;
	unsigned long modlen;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long data_ptr;
	unsigned long restlen;
	unsigned char paket_len;
	unsigned char req_len;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBdlI_typ;

typedef struct PBkeyena
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long ena_ptr;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PBkeyena_typ;

typedef struct PBkeyon
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long key_ptr;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PBkeyon_typ;

typedef struct PBwrDPR
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short offset;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long phy_adr_merker;
	unsigned long data_ptr;
	unsigned short restlen;
	unsigned char paket_len;
	unsigned char req_len;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBwrDPR_typ;

typedef struct PBsyncKR
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned char dir;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned char count;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PBsyncKR_typ;

typedef struct PBdlN
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long modname;
	unsigned long modptr;
	unsigned long modlen;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	unsigned long data_ptr;
	unsigned long restlen;
	unsigned char paket_len;
	unsigned char req_len;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBdlN_typ;

typedef struct PBgetOVM
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short startind;
	unsigned long ovliste;
	unsigned char maxobj;
	unsigned char long_ver;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned char obj_cnt;
	unsigned char morefoll;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBgetOVM_typ;

typedef struct PBgetOVN
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned char spec_id;
	unsigned long name;
	unsigned char long_ver;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned char obj_len;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBgetOVN_typ;

typedef struct PBgetOVI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned char long_ver;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned char obj_len;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBgetOVI_typ;

typedef struct PBdelVLI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBdelVLI_typ;

typedef struct PBstatKR
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned char status;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
} PBstatKR_typ;

typedef struct PBirepI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned short subindex;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBirepI_typ;

typedef struct PBdefVLI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long liste;
	unsigned char anzahl;
	unsigned char pw;
	unsigned char group;
	unsigned short rights;
	unsigned long name;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned short newindex;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBdefVLI_typ;

typedef struct PBdefVLN
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long liste;
	unsigned char anzahl;
	unsigned char pw;
	unsigned char group;
	unsigned short rights;
	unsigned long name;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned short newindex;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBdefVLN_typ;

typedef struct PBwrDVL
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned long liste;
	unsigned char anzahl;
	unsigned char ind_phy;
	unsigned long data;
	unsigned short len;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBwrDVL_typ;

typedef struct PBustat
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned char log_stat;
	unsigned char phy_stat;
	unsigned long ld_ptr;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBustat_typ;

typedef struct PBackevI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned char ev_nr;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBackevI_typ;

typedef struct PBaltevI
{
	/* VAR_INPUT (analog) */
	unsigned short kr;
	unsigned short index;
	unsigned char ev_en;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBaltevI_typ;

typedef struct PBsend
{
	/* VAR_INPUT (analog) */
	unsigned long par_ptr;
	unsigned long send_ptr;
	/* VAR_OUTPUT (analog) */
	unsigned short error_nr;
	unsigned long rec_ptr;
	/* VAR (analog) */
	struct PBInternalStruct StaticStruct;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit ready;
} PBsend_typ;



/* Prototyping of functions and function blocks */
void PBreadI(struct PBreadI* inst);
void PBreadN(struct PBreadN* inst);
void PBwriteI(struct PBwriteI* inst);
void PBwriteN(struct PBwriteN* inst);
void PBwriteP(struct PBwriteP* inst);
void PBreadP(struct PBreadP* inst);
void PBautoKR(struct PBautoKR* inst);
void PBinfoKR(struct PBinfoKR* inst);
void PBrdDVL(struct PBrdDVL* inst);
void PBreadX(struct PBreadX* inst);
void PBrec(struct PBrec* inst);
void PBevnotI(struct PBevnotI* inst);
void PBdelVLN(struct PBdelVLN* inst);
void PBrdDPR(struct PBrdDPR* inst);
void PBinit(struct PBinit* inst);
void PBwriteX(struct PBwriteX* inst);
void PBdlI(struct PBdlI* inst);
void PBkeyena(struct PBkeyena* inst);
void PBkeyon(struct PBkeyon* inst);
void PBwrDPR(struct PBwrDPR* inst);
void PBsyncKR(struct PBsyncKR* inst);
void PBdlN(struct PBdlN* inst);
void PBgetOVM(struct PBgetOVM* inst);
void PBgetOVN(struct PBgetOVN* inst);
void PBgetOVI(struct PBgetOVI* inst);
void PBdelVLI(struct PBdelVLI* inst);
void PBstatKR(struct PBstatKR* inst);
void PBirepI(struct PBirepI* inst);
void PBdefVLI(struct PBdefVLI* inst);
void PBdefVLN(struct PBdefVLN* inst);
void PBwrDVL(struct PBwrDVL* inst);
void PBustat(struct PBustat* inst);
void PBackevI(struct PBackevI* inst);
void PBaltevI(struct PBaltevI* inst);
void PBsend(struct PBsend* inst);


#ifdef __cplusplus
};
#endif
#endif /* _PB_LIB_ */

                                                           
