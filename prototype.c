
/* *** Copyright Freescale Semiconductor, Inc, 2005 *** */

/********************************************************************

   Predefined basic intrinsics.

   Builtin support for these function is implemented in the
   compiler code generator

   On hosted systems this file implements the fractional type 
   emulation of the built in functions.

 ********************************************************************/
#include "prototype.h"

/*Conditionnal replacement of prototype functions                                       */
/* _ENTERPRISE_C_ is always defined by scc/IDE, and may appear in customers applications*/
/* _CW_NO_PROTO_REPLACE_ can be defined to prevent replacement of prototype functions   */
/*Replacement performed iff first defined, second undefined. Otherwise use definitions	*/
/*in prototype.c									*/

#ifdef _ENTERPRISE_C_
#ifndef _CW_NO_PROTO_REPLACE_
#ifndef _CW_X_PROTO_
#define _CW_X_PROTO_
#endif
#endif
#endif

#ifdef _CW_X_PROTO_
/*___________________________________________________________________________
 |                                                                           |
 |   Functions:
 |     Pre-defined intrinsics                                                |
 |___________________________________________________________________________|
*/

Word32 add2 (Word32 var1, Word32 var2) {return 0;}
Word32 sub2 (Word32 var1, Word32 var2) {return 0;}
Word32 max2 (Word32 var1, Word32 var2) {return 0;}
Word32 min2 (Word32 var1, Word32 var2) {return 0;}

Word16 add (Word16 var1, Word16 var2) {return 0;}
Word16 sub (Word16 var1, Word16 var2) {return 0;}
Word16 abs_s (Word16 var1) {return 0;}
Word16 shl (Word16 var1, Word16 var2) {return 0;}
Word16 shl_nosat (Word16 var1, Word16 var2) {return 0;}
Word16 shr (Word16 var1, Word16 var2) {return 0;}
Word16 shr_nosat (Word16 var1, Word16 var2) {return 0;}
Word16 mult (Word16 var1, Word16 var2) {return 0;}
Word16 mult_nomac (Word16 var1, Word16 var2) {return 0;}
Word32 L_mult (Word16 var1, Word16 var2) {return 0;}
Word32 L_mult_nomac (Word16 var1, Word16 var2) {return 0;}
Word16 negate (Word16 var1) {return 0;}
Word16 extract_h (Word32 L_var1) {return 0;}
Word16 extract_l (Word32 L_var1) {return 0;}
Word16 round2 (Word32 L_var1) {return 0;}
Word16 max (Word16 var1, Word16 var2) {return 0;}
UWord16 maxu (UWord16 var1, UWord16 var2) {return 0;}
Word16 min (Word16 var1, Word16 var2) {return 0;}
UWord16 minu (UWord16 var1, UWord16 var2) {return 0;}
Word16 maxm (Word16 var1, Word16 var2) {return 0;}
Word16 saturate (Word32 L_var1) { return 0;}
Word32 div_iter (Word32 var1, Word16 var2) { return 0;}

Word32 L_add (Word32 L_var1, Word32 L_var2) {return 0;}
Word32 L_sub (Word32 L_var1, Word32 L_var2) {return 0;}
Word32 L_negate (Word32 L_var1) {return 0;}
Word16 mult_r (Word16 var1, Word16 var2) {return 0;}
Word32 L_shl (Word32 L_var1, Word16 var2) {return 0;}
Word32 L_shl_nosat (Word32 L_var1, Word16 var2) {return 0;}
Word32 L_shr (Word32 L_var1, Word16 var2) {return 0;}
Word32 L_shr_nosat (Word32 L_var1, Word16 var2) {return 0;}
Word32 L_deposit_h (Word16 var1) {return 0;}
Word32 L_deposit_l (Word16 var1) {return 0;}
Word32 L_abs (Word32 L_var1) {return 0;}
Word16 norm_s (Word16 var1) {return 0;}
Word16 norm_su (UWord16 var1) {return 0;}
Word16 neg_norm_s (Word16 var1) {return 0;}
Word16 neg_norm_su (UWord16 var1) {return 0;}
Word16 norm_l (Word32 L_var1) {return 0;}
Word16 norm_lu (UWord32 L_var1) {return 0;}
Word16 neg_norm_l (Word32 L_var1) {return 0;}
Word16 neg_norm_lu (UWord32 L_var1) {return 0;}
Word32 L_max (Word32 L_var1, Word32 L_var2) {return 0;}
UWord32 L_maxu (UWord32 L_var1, UWord32 L_var2) {return 0;}
Word32 L_min (Word32 L_var1, Word32 L_var2) {return 0;}
UWord32 L_minu (UWord32 L_var1, UWord32 L_var2) {return 0;}
Word32 L_maxm (Word32 L_var1, Word32 L_var2) {return 0;}
Word32 L_sat (Word32 L_var1) { return 0;}
Word16 load_fr(Word16 a) { return 0;}
Word16 load_fr_ext_val_none(Word16 a) { return 0;}
Word32 load_lfr_ext_val_val(Word32 a) { return 0;}

void clearEMRbit(int value) { }

void setsat32() { }
void setnosat() { }
void set2crm() { }
void setcnvrm() { }
void trap_r(void * Par) {}
int trap_d(int Par) {return 0;}

void trap0_r(void * Par) {}
void trap1_r(void * Par) {}
void trap2_r(void * Par) {}
void trap3_r(void * Par) {}

int trap0_d(int Par) {return 0;}
int trap1_d(int Par) {return 0;}
int trap2_d(int Par) {return 0;}
int trap3_d(int Par) {return 0;}

void ei() {}
void di() {}
void * Ovl_Load_Address(void * Symb_Addr) {return Symb_Addr;}

void Set_Overflow(Word32 Value) {}
int Get_Overflow() {return 0;}
int Test_Overflow() {return 0;}

int _GetCoreId() {return 1;}

Word32 Clip(Word32 Value, Word32 mask) {return 0;}

Word32 Extract(Word32 Val, UWord32 Mask) {return 0;}
UWord32 ExtractU(UWord32 Val, UWord32 Mask) {return 0;}

Word32 Extract_reg(Word32 Val, UWord32 Mask) {return 0;}
UWord32 ExtractU_reg(UWord32 Val, UWord32 Mask) {return 0;}

int readSR(void) {return 0;}
void writeSR(int Val) {}
void *readOSP(void) {return 0;}
void writeOSP(void *Val) {}
void setPPL(int Val) {}

void clearSRbit(int bitmask) {}
void setSRbit(int bitmask) {}

void cw_assert(int a) {}

int br_swap(int index, int max_val) {return 0;}
/* Warning here we use the _ prefix since br_inc(a, b) is redefined as br_inc(a, b<<1) in  prototype.h */
int _br_inc(int index, int max_val) {return 0;}
/* int br_inc_nu(int index, int max_val, int step) {return 0;} */

/*****************************************************/
/* Double precision fractional arithmetic primitives */
/*****************************************************/

Word64 D_set(Word32 left , UWord32 right)
{
  Word64 local = {0,0}; return local; 
}

Word32 D_get_msb(Word64 Val)
{
return Val.msb;
}

Word32 D_get_lsb(Word64 Val)
{
return Val.lsb;
}

#ifdef _CW_X_SLLD_
Word32 LL_get_msb(Int64 Val)
{
	return (Val>>32);
}

UWord32 LL_get_lsb(Int64 Val)
{
	return Val;
}

Word32 Db_get_msb(double Val)
{
	union {
		Int64 L;
		double D;
	} X;
	X.D = Val;

	return (X.L>>32);
}

UWord32 Db_get_lsb(double Val)

{
	union {
		Int64 L;
		double D;
	} X;
	X.D = Val;
	return  (X.L);
}

Int64 Db_to_LL(double Val)

{
	union {
		Int64 L;
		double D;
	} X;
	X.D = Val;
	return  (X.L);
}

double LL_to_Db(Int64 Val)

{
	union {
		Int64 L;
		double D;
	} X;
	X.L = Val;
	return  (X.D);
}
#endif

Word64 D_add (Word64 D_var1, Word64 D_var2) 
{ 
  Word64 local = {0,0}; return local; 
}
Word64 D_add_opt (Word64 D_var1, Word64 D_var2) 
{ 
  Word64 local = {0,0}; return local; 
}
Word64 D_sub (Word64 D_var1, Word64 D_var2) 
{ 
  Word64 local = {0,0}; return local; 
}

Word64 D_mult (Word32 L_var1, Word32 L_var2 ) 
{ 
  Word64 local = {0,0}; return local; 
}

Word64 D_mult_opt (Word32 L_var1, Word32 L_var2 ) 
{ 
  Word64 local = {0,0}; return local; 
}

Word32 D_mult_msp (Word32 L_var1, Word32 L_var2 ) 
{ 
  Word32 local = 0; return local; 
}

int D_cmpeq (Word64 D_var1, Word64 D_var2) { return 0; }
int D_cmpgt (Word64 D_var1, Word64 D_var2) { return 0; }

Word64 D_sat (Word64 D_var1) 
{ 
  Word64 local = {0,0}; return local; 
}

Word32  D_round  (Word64 D_var1) { return 0; }

Word16 norm_ll (Word64 L_var1) {return 0;}
Word16 neg_norm_ll (Word64 L_var1) {return 0;}


/*****************************************************/
/* Extended precision fractional arithmetic primitives */
/*****************************************************/

Word40 X_set(Word32 guard, UWord32 body) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_extend (Word32 var1) 
{
  Word40 local = {0,0}; return local; 
}

Word16 X_extract_h (Word40 var1) { return 0; }
Word16 X_extract_l (Word40 var1) { return 0; }
Word16 X_round (Word40 var1) { return 0; }
Word16 X_norm (Word40 var1) { return 0; }
Word32 X_trunc (Word40 var1) { return 0; }
Word32 X_guard (Word40 var1) { return 0; }

Word40 X_add (Word40 var1, Word40 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_add_sat (Word40 var1, Word40 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_sub (Word40 var1, Word40 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_sub_sat (Word40 var1, Word40 var2) 
{
  Word40 local = {0,0}; return local; 
}


Word40 X_mult (Word16 var1, Word16 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_shl (Word40 var1, Word16 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_shl_sat (Word40 var1, Word16 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_shr (Word40 var1, Word16 var2) 
{
  Word40 local = {0,0}; return local; 
}
Word40 X_lsl (Word40 var1, Word16 var2) 
{
  Word40 local = {0,0}; return local; 
}
Word40 X_lsr (Word40 var1, Word16 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_abs (Word40 var1) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_abs_sat (Word40 var1) 
{
  Word40 local = {0,0}; return local; 
}

Word32 X_sat (Word40 var1) { return 0; }

Word40 X_or (Word40 var1, Word40 var2) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_xor (Word40 var1, Word40 var2) 
{
  Word40 local = {0,0}; return local; 
}

int    X_cmpeq(Word40 var1, Word40 var2) { return 0; }
int    X_cmpgt(Word40 var1, Word40 var2) { return 0; }

Word40 X_ror (Word40 var1) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_ror_unsafe (Word40 var1) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_rol (Word40 var1) 
{
  Word40 local = {0,0}; return local; 
}

Word40 X_rol_unsafe (Word40 var1) 
{
  Word40 local = {0,0}; return local; 
}


void* __clear(void *src, unsigned int size) { return src; }


/*****************************************************/
/* V5: Dfetch				                         */
/*****************************************************/

void _dfetch(void *mem_line) {}
void _pfetch(void *mem_line) {}
void _pfetch_imm(void *imm_address) {}

/* V5 packed moves */
Word8 read_b(Word8* addr) { return 0; }
Word32 read_l(Word32* addr) { return 0; }

void write_b(Word8* addr, Word8 src) {}
void write_l(Word32* src1, Word32 src2) {} 

/*****************************************************/
/* V5: Syncio, Syncm Support                         */
/*****************************************************/

void _syncio() {}
void _syncm()  {}
void _syncio_barrier() {}

/*syncio load*/
char syncio_read_b(volatile char *src) { return 0; }
unsigned char syncio_read_ub(volatile unsigned char *src) { return 0; }
short syncio_read_w(volatile short *src) { return 0; }
unsigned short syncio_read_uw(volatile unsigned short *src)  { return 0; }
int syncio_read_l(volatile int *src)  { return 0; }
unsigned int syncio_read_ul(volatile unsigned int *src)  { return 0; }

/*syncm load*/
char syncm_read_b(volatile char *src)  { return 0; }
unsigned char syncm_read_ub(volatile unsigned char *src)  { return 0; }
short syncm_read_w(volatile short *src)  { return 0; }
unsigned short syncm_read_uw(volatile unsigned short *src)  { return 0; }
int syncm_read_l(volatile int *src)  { return 0; }
unsigned int syncm_read_ul(volatile unsigned int *src)  { return 0; }

/*syncio store*/
void syncio_write_b(volatile char *dst, char src) { *dst = 0; }
void syncio_write_ub(volatile unsigned char *dst, unsigned char src)  { *dst = 0; }
void syncio_write_w(volatile short *dst, short src)  { *dst = 0; }
void syncio_write_uw(volatile unsigned short *dst, unsigned short src)  { *dst = 0; }
void syncio_write_l(volatile int *dst, int src)  { *dst = 0; }
void syncio_write_ul(volatile unsigned int *dst, unsigned int src)  { *dst = 0; }

/*syncm store*/
void syncm_write_b(volatile char *dst, char src)  { *dst = 0; }
void syncm_write_ub(volatile unsigned char *dst, unsigned char src)  { *dst = 0; }
void syncm_write_w(volatile short *dst, short src)  { *dst = 0; }
void syncm_write_uw(volatile unsigned short *dst, unsigned short src)  { *dst = 0; }
void syncm_write_l(volatile int *dst, int src)  { *dst = 0; }
void syncm_write_ul(volatile unsigned int *dst, unsigned int src)  { *dst = 0; }

/* scaling*/
void force_moves_f(Word16 *ptr, Word16 src) { *ptr = src; }
void force_moves_l(long *ptr, long src) { *ptr = src; }

/* unaligned access */
long *setalign(long *src) {}
long unaligned_load(long *src) {return *src;}

/*****************************************************/
/* V5: Vector Support                                */
/*****************************************************/

Vector_Type32 V_pack_2w(Vector_Type32 src_var1, Vector_Type32 src_var2) { return 0; }

Vector_Type32 V_pack_2fr(Vector_Type32 src_var1, Vector_Type32 src_var2) { return 0; }

Vector_Component16 V_unpack_2w1(Vector_Type32 src_vect) { 	return 0; }

Vector_Type32 V_read2_2b(Vector_Component8 *src_mem) { return 0; }

Vector_Type32 V_read2_2ub(Vector_ComponentU8 *src_mem) { return 0; }

void V_write2_2b(Vector_Component8 *dst_mem, Vector_Type32 src_vect) 
{ 
	*dst_mem = 0; 
	*((char*)dst_mem+1) = 0;
}

Vector_Type32 V_read2_2b4(Vector_Component8 *src_mem) { return 0; }

Vector_Type32 V_read2_2ub4(Vector_ComponentU8 *src_mem) { return 0; }

void V_write2_2b4(Vector_Component8 *dst_mem, Vector_Type32 src_vect) 
{ 
	*dst_mem = 0; 
	*((char*)dst_mem+1) = 0;
}

Vector_Type32 V_read2_2b8(Vector_Component8 *src_mem) { return 0; }

Vector_Type32 V_read2_2ub8(Vector_ComponentU8 *src_mem) { return 0; }

void V_write2_2b8(Vector_Component8 *dst_mem, Vector_Type32 src_vect) 
{ 
	*dst_mem = 0; 
	*((char*)dst_mem+1) = 0;
}

Vector_Type32 V_read_w(Vector_Component16 *src_mem, Vector_Type32 src_vect) { return 0; }
Vector_Type32 V_read_fr(Vector_Component16 *src_mem, Vector_Type32 src_vect) { return 0; }

/* modify - swap, tfr */
Vector_Type32 V_swap(Vector_Type32 a) { return 0; }
Vector_Type32 V_swapb(Vector_Type32 src_vect) { return 0; }
Vector_Type32 V_swapb2(Vector_Type32 src_vect) { return 0; }

/* tfr.w */
Vector_Type32 V_tfrw_ll(Vector_Type32 dest, Vector_Type32 src) {};
Vector_Type32 V_tfrw_lh(Vector_Type32 dest, Vector_Type32 src) {};
Vector_Type32 V_tfrw_hl(Vector_Type32 dest, Vector_Type32 src) {};
Vector_Type32 V_tfrw_hh(Vector_Type32 dest, Vector_Type32 src) {};

/* world level copy */
Vector_Type32 V_pack_ll_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_pack_lh_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_pack_hl_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_pack_hh_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }

Vector_Type32 V_add_w_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_add_w_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_add_w_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_add_w_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sub_w_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sub_w_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sub_w_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sub_w_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }

Vector_Type32 V_sod2aaii(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sod2aaxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sod2asii(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sod2asxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sod2saii(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sod2saxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sod2ssii(Vector_Type32 src_vect2, Vector_Type32 src_vect1) { return 0; }
Vector_Type32 V_sod2ssxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }

/*
Vector_Type32 V_add2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_sub2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
*/
Vector_Type32 V_abs2(Vector_Type32 src_vect1) { return 0; }
Vector_Type32 V_neg2(Vector_Type32 src_vect1) { return 0; }
/*
Vector_Type32 V_max2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_min2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
*/

Vector_Type32 V_asl2(Vector_Type32 src_vect) { return 0; }
Vector_Type32 V_asll2(Vector_Type32 src_vect, int val)  { return 0; }
Vector_Type32 V_asr2(Vector_Type32 src_vect)  { return 0; }
Vector_Type32 V_asrr2(Vector_Type32 src_vect, int val)  { return 0; }
Vector_Type32 V_lsll2(Vector_Type32 src_vect, int val)  { return 0; }
Vector_Type32 V_lsr2(Vector_Type32 src_vect)  { return 0; }
Vector_Type32 V_lsrr2(Vector_Type32 src_vect, int val)  { return 0; }

Vector_Type32 V_satu2b(Vector_Type32 src_vect) { return 0; }
Vector_Type32 V_avgu4(Vector_Type32 src_vect1, Vector_Type32 src_vect2)  { return 0; }

Word40 V_imacsu2_mpy(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{ 
  Word40 local = {0,0}; return local; 
}

Word40 V_impysu2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{ 
  Word40 local = {0,0}; return local; 
}

/*Vector_Type32 V_sr4t(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }*/

Word40 V_clip2(Word40 src_vect, int imm)

{ 
  Word40 local = {0,0}; return local; 
}


void V_dummy_read_32(Vector_Type32 src_vect) { }

Vector_Type32 V_sad41(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }
Vector_Type32 V_dummy_read_2x32(Vector_Type32 src_vect1, Vector_Type32 src_vect2) { return 0; }

Word40 V_add2_20Component(Word40 src_vect1, Word40 src_vect2)

{
  Word40 local = {0,0}; return local; 
}


/*mpy instructions*/
Vector_Component16 V_mult_hh(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hh(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hh_add(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hh_sub(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hh_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hh_sub_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type40 V_X_mult_hh(Vector_Type32 var1, Vector_Type32 var2) 

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_hh_add(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_hh_sub(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Component16 V_mult_lh(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_lh(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_lh_add(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_lh_sub(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_lh_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_lh_sub_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type40 V_X_mult_lh(Vector_Type32 var1, Vector_Type32 var2) 

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_lh_add(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_lh_sub(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Component16 V_mult_hl(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hl(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hl_add(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hl_sub(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hl_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_hl_sub_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type40 V_X_mult_hl(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_hl_add(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_hl_sub(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Component16 V_mult_ll(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_ll(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_ll_add(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_ll_sub(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_ll_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type32 V_L_mult_ll_sub_round(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Type40 V_X_mult_ll(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_ll_add(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}

Vector_Type40 V_X_mult_ll_sub(Vector_Type32 var1, Vector_Type32 var2)

{
  Word40 local = {0,0}; return local; 
}


/*mpyr instructions*/
Vector_Component16 V_mult_r_hh(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Component16 V_mult_r_lh(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Component16 V_mult_r_hl(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

Vector_Component16 V_mult_r_ll(Vector_Type32 var1, Vector_Type32 var2) { return 0; }

/* End V5 Vector Support */


/*****************************************************/
/* Other primitives                                  */
/*****************************************************/

Word32 mpyuu( Word32 var1, Word32 var2 ) { return 0; }
Word32 mpyus( Word32 var1, Word32 var2 ) { return 0; }
Word32 mpyus_shr16(Word32 var1, Word16 var2) {return 0;}
Word32 mpysu_shr16(Word16 var1, Word32 var2) {return 0;}
Word32 L_mult_ls(Word32 var1, Word16 var2) {return 0;}
Word32 L_mult_sl(Word16 var2, Word32 var1) {return 0;}
Word32 mpysu( Word32 var1, Word32 var2 ) { return 0; }

/*void Write_64(Word64 * Fifo, Word64 Value) {return;}*/
/*Word64 Read_64(const Word64 * Fifo) {Word64 Res = {0, 0}; return Res;}*/
int bmtset(Word16 Sema, unsigned short mask) { return 0;}
#else

#include <stdio.h>
#include <stdlib.h>

/*___________________________________________________________________________
 |                                                                           |
 |   Constants and Globals                                                   |
 |___________________________________________________________________________|
*/
Flag Overflow = 0;
Flag Carry = 0;
Flag SaturationMode = 1;


/* Multi precison functions */

unsigned int B_SET_VECTOR_MASK[] = {
	1<<0, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7, 1<<8, 1<<9, 1<<10, 1<<11, 1<<12, 1<<13, 1<<14, 1<<15,
	1<<16, 1<<17, 1<<18, 1<<19, 1<<20, 1<<21, 1<<22, 1<<23, 1<<24, 1<<25, 1<<26, 1<<27, 1<<28, 1<<29, 1<<30, 1<<31};

unsigned int B_RES_VECTOR_MASK[] = {
	(~(1<<0)), (~(1<<1)), (~(1<<2)), (~(1<<3)), (~(1<<4)), (~(1<<5)), (~(1<<6)), (~(1<<7)), (~(1<<8)), (~(1<<9)),
	(~(1<<10)), (~(1<<11)), (~(1<<12)), (~(1<<13)), (~(1<<14)), (~(1<<15)), (~(1<<16)), (~(1<<17)), (~(1<<18)),
	(~(1<<19)), (~(1<<20)), (~(1<<21)), (~(1<<22)), (~(1<<23)), (~(1<<24)), (~(1<<25)), (~(1<<26)), (~(1<<27)),
	(~(1<<28)), (~(1<<29)), (~(1<<30)), (~(1<<31)) };

#define BIT_S(b_vector, bit_number) ((b_vector[bit_number >> 5] |= B_SET_VECTOR_MASK[bit_number & 31]))
#define BIT_R(b_vector, bit_number) ((b_vector[bit_number >> 5] &= B_RES_VECTOR_MASK[bit_number & 31]))
#define BIT_V(b_vector, bit_number) ((b_vector[bit_number >> 5] & B_SET_VECTOR_MASK[bit_number & 31]))

void Set_Vect(unsigned int *To_Vect, unsigned int *From_Vect, int len)

{
	int i;

	for (i = 0; i<len; i++) if (BIT_V(From_Vect, i)) BIT_S(To_Vect, i); else BIT_R(To_Vect, i);
}

void ADD(unsigned int *X, unsigned int *Y, unsigned int *Res, int len)

{
	int i, Out, C = 0;
	int V1, V2;

	for (i = 0; i<len; i++) {
		V1 = (BIT_V(X, i) != 0) ; V2 = (BIT_V(Y, i) != 0);
		Out = V1^V2^C;
		if (Out) BIT_S(Res, i); else BIT_R(Res, i);
		C = (V1 + V2 + C) >= 2;
		
	}
}

void MINUS(unsigned int *X, unsigned int *Y, unsigned int *Res, int len)

{
	int i;
	unsigned int Temp_V[2] = {0, 0};
	unsigned int Temp_V1[2] = {0, 0};

	BIT_S(Temp_V1, 0);
	Set_Vect(Temp_V, Y, len);
	for (i = 0; i<len; i++) if (BIT_V(Temp_V, i)) BIT_R(Temp_V, i); else BIT_S(Temp_V, i); /* !Y */
	ADD(Temp_V, Temp_V1, Temp_V, len);			/* !Y + 1 */
	ADD(X, Temp_V, Res, len);				/* X + !Y + 1 */
}



Word40 X_SUB(Word40 a, Word40 b)

{
	Word40 c;
	unsigned int A[] = {0, 0};
	unsigned int B[] = {0, 0};
	unsigned int R[] = {0, 0};
	int v1 = a.body;
	int v2 = a.ext;
	int v3 = b.body;
	int v4 = b.ext;

	Set_Vect(&A[0], &v1, 32); Set_Vect(&A[1], &v2, 8);
	Set_Vect(&B[0], &v3, 32); Set_Vect(&B[1], &v4, 8);
	A[0] = v1; A[1] = v2;
	B[0] = v3; B[1] = v4;
	MINUS(A, B, R, 40);
	c.ext = R[1]; c.body = R[0];
	return c;
}

Word64 D_SUB(Word64 a, Word64 b)

{
	Word64 c;
	unsigned int A[] = {0, 0};
	unsigned int B[] = {0, 0};
	unsigned int R[] = {0, 0};
	int v1 = a.lsb;
	int v2 = a.msb;
	int v3 = b.lsb;
	int v4 = b.msb;

	Set_Vect(&A[0], &v1, 32); Set_Vect(&A[1], &v2, 32);
	Set_Vect(&B[0], &v3, 32); Set_Vect(&B[1], &v4, 32);
	A[0] = v1; A[1] = v2;
	B[0] = v3; B[1] = v4;
	MINUS(A, B, R, 64);
	c.msb = R[1]; c.lsb = R[0];
	return c;
}

Word40 X_ADD(Word40 a, Word40 b)

{
	Word40 c;
	unsigned int A[] = {0, 0};
	unsigned int B[] = {0, 0};
	unsigned int R[] = {0, 0};
	int v1 = a.body;
	int v2 = a.ext;
	int v3 = b.body;
	int v4 = b.ext;

	Set_Vect(&A[0], &v1, 32); Set_Vect(&A[1], &v2, 8);
	Set_Vect(&B[0], &v3, 32); Set_Vect(&B[1], &v4, 8);
	A[0] = v1; A[1] = v2;
	B[0] = v3; B[1] = v4;
	ADD(A, B, R, 40);
	c.ext = R[1]; c.body = R[0];
	return c;
}

Word64 D_ADD(Word64 a, Word64 b)

{
	Word64 c;
	unsigned int A[] = {0, 0};
	unsigned int B[] = {0, 0};
	unsigned int R[] = {0, 0};
	int v1 = a.lsb;
	int v2 = a.msb;
	int v3 = b.lsb;
	int v4 = b.msb;

	Set_Vect(&A[0], &v1, 32); Set_Vect(&A[1], &v2, 32);
	Set_Vect(&B[0], &v3, 32); Set_Vect(&B[1], &v4, 32);
	A[0] = v1; A[1] = v2;
	B[0] = v3; B[1] = v4;
	ADD(A, B, R, 64);
	c.msb = R[1]; c.lsb = R[0];
	return c;
}

static Word32 L_add_c (Word32 L_var1, Word32 L_var2);
static Word32 L_sub_c (Word32 L_var1, Word32 L_var2);

static Word32 L_macNs (Word32 L_var3, Word16 var1, Word16 var2);
static Word32 L_msuNs (Word32 L_var3, Word16 var1, Word16 var2);

/*___________________________________________________________________________
 |                                                                           |
 |   Functions:
 |___________________________________________________________________________|
*/

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : saturate                                                |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |    Limit the 32 bit input to the range of a 16 bit word.                  |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var1 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 saturate (Word32 L_var1)
{
    Word16 var_out;

    if (L_var1 > 0X00007fffL)
    {
        Overflow = 1;
        var_out = MAX_16;
    }
    else if (L_var1 < (Word32) 0xffff8000L)
    {
        Overflow = 1;
        var_out = MIN_16;
    }
    else
    {
        Overflow = 0;
        var_out = extract_l (L_var1);
    }

    return (var_out);
}

Word32 add2(Word32 a, Word32 b)

{
        Word32 v1, v2;

        v1 = (a + b) & (0x0FFFF);
        v2 = ((a & 0xFFFF0000) + (b & 0xFFFF0000));
        return (v1 | v2);
}

Word32 sub2(Word32 a, Word32 b)

{
        Word32 v1, v2;

        v1 = ((short) a - (short) b) & (0x0FFFF);
        v2 = (((short) (a >> 16) - (short) (b >> 16)) << 16) & 0xFFFF0000;
        return (v1 | v2);
}

Word32 max2(Word32 a, Word32 b)

{
        Word32 v1, v2;

        v1 = ((short) a > (short) b) ? (a & 0x0FFFF):(b & 0x0FFFF);
        v2 = ((short) (a >> 16) > (short) (b >> 16)) ?
                (a & 0xFFFF0000):(b & 0xFFFF0000);

        return (v1 | v2);
}

Word32 min2(Word32 a, Word32 b)

{
        Word32 v1, v2;

        v1 = ((short) a < (short) b) ? (a & 0x0FFFF):(b & 0x0FFFF);
        v2 = ((short) (a >> 16) < (short) (b >> 16)) ?
                (a & 0xFFFF0000):(b & 0xFFFF0000);

        return (v1 | v2);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : add                                                     |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |    Performs the addition (var1+var2) with overflow control and saturation;|
 |    the 16 bit result is set at +32767 when overflow occurs or at -32768   |
 |    when underflow occurs.                                                 |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 add (Word16 var1, Word16 var2)
{
    Word16 var_out;
    Word32 L_sum;

    L_sum = (Word32) var1 + var2;
    var_out = saturate (L_sum);
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : sub                                                     |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |    Performs the subtraction (var1+var2) with overflow control and satu-   |
 |    ration; the 16 bit result is set at +32767 when overflow occurs or at  |
 |    -32768 when underflow occurs.                                          |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 sub (Word16 var1, Word16 var2)
{
    Word16 var_out;
    Word32 L_diff;

    L_diff = (Word32) var1 - var2;
    var_out = saturate (L_diff);
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : abs_s                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |    Absolute value of var1; abs_s(-32768) = 32767.                         |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 0000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 abs_s (Word16 var1)
{
    Word16 var_out;

    if (var1 == (Word16) 0X8000)
    {
        var_out = MAX_16;
    }
    else
    {
        if (var1 < 0)
        {
            var_out = -var1;
        }
        else
        {
            var_out = var1;
        }
    }
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : shl                                                     |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Arithmetically shift the 16 bit input var1 left var2 positions.Zero fill|
 |   the var2 LSB of the result. If var2 is negative, arithmetically shift   |
 |   var1 right by -var2 with sign extension. Saturate the result in case of |
 |   underflows or overflows.                                                |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 shl (Word16 var1, Word16 var2)
{
    Word16 var_out;
    Word32 result;

    if (var2 < 0)
      var_out = shr (var1, -var2);
    else
    {
        result = (Word32) var1 *((Word32) 1 << var2);

        if ((var2 > 15 && var1 != 0) || (result != (Word32) ((Word16) result)))
        {
            Overflow = 1;
            var_out = (var1 > 0) ? MAX_16 : MIN_16;
        }
        else
          var_out = extract_l (result);
    }
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : shr                                                     |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Arithmetically shift the 16 bit input var1 right var2 positions with    |
 |   sign extension. If var2 is negative, arithmetically shift var1 left by  |
 |   -var2 with sign extension. Saturate the result in case of underflows or |
 |   overflows.                                                              |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 shr (Word16 var1, Word16 var2)
{
    Word16 var_out;

    if (var2 < 0)
      var_out = shl (var1, -var2);
    else if (var2 >= 15)
      var_out = (var1 < 0) ? -1 : 0;
    else if (var1 < 0)
      var_out = ~((~var1) >> var2);
    else
      var_out = var1 >> var2;

    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : mult                                                    |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |    Performs the multiplication of var1 by var2 and gives a 16 bit result  |
 |    which is scaled i.e.:                                                  |
 |             mult(var1,var2) = extract_l(L_shr((var1 times var2),15)) and  |
 |             mult(-32768,-32768) = 32767.                                  |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 mult (Word16 var1, Word16 var2)
{
    Word16 var_out;
    Word32 L_product;

    L_product = (Word32) var1 *(Word32) var2;

    L_product = (L_product & (Word32) 0xffff8000L) >> 15;

    if (L_product & (Word32) 0x00010000L)
        L_product = L_product | (Word32) 0xffff0000L;

    var_out = saturate (L_product);
    return (var_out);
}

Word16 mult_nomac (Word16 var1, Word16 var2)
{
    return mult(var1, var2);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_mult                                                  |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   L_mult is the 32 bit result of the multiplication of var1 times var2    |
 |   with one shift left i.e.:                                               |
 |        L_mult(var1,var2) = L_shl((var1 times var2),1) and                 |
 |        L_mult(-32768,-32768) = 2147483647.                                |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_mult (Word16 var1, Word16 var2)
{
    Word32 L_var_out;

    L_var_out = (Word32) var1 *(Word32) var2;

    if (L_var_out != (Word32) 0x40000000L)
      L_var_out *= 2;
    else
    {
        Overflow = 1;
        L_var_out = MAX_32;
    }

    return (L_var_out);
}

Word32 L_mult_nomac (Word16 var1, Word16 var2)
{
	return L_mult(var1, var2);
}


/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : negate                                                  |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Negate var1 with saturation, saturate in the case where input is -32768:|
 |                negate(var1) = sub(0,var1).                                |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 negate (Word16 var1)
{
    Word16 var_out;

    var_out = (var1 == MIN_16) ? MAX_16 : -var1;
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : extract_h                                               |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Return the 16 MSB of L_var1.                                            |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32 ) whose value falls in the |
 |             range : 0x8000 0000 <= L_var1 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 extract_h (Word32 L_var1)
{
    Word16 var_out;

    var_out = (Word16) (L_var1 >> 16);
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : extract_l                                               |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Return the 16 LSB of L_var1.                                            |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32 ) whose value falls in the |
 |             range : 0x8000 0000 <= L_var1 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 extract_l (Word32 L_var1)
{
    Word16 var_out;

    var_out = (Word16) L_var1;
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : round                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Round the lower 16 bits of the 32 bit input number into the MS 16 bits  |
 |   with saturation. Shift the resulting bits right by 16 and return the 16 |
 |   bit number:                                                             |
 |               round(L_var1) = extract_h(L_add(L_var1,32768))              |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32 ) whose value falls in the |
 |             range : 0x8000 0000 <= L_var1 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 round2 (Word32 L_var1)
{
    Word16 var_out;
    Word32 L_rounded;

    L_rounded = L_add (L_var1, (Word32) 0x00008000L);
    var_out = extract_h (L_rounded);
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_mac                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Multiply var1 by var2 and shift the result left by 1. Add the 32 bit    |
 |   result to L_var3 with saturation, return a 32 bit result:               |
 |        L_mac(L_var3,var1,var2) = L_add(L_var3,L_mult(var1,var2)).         |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var3   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_mac (Word32 L_var3, Word16 var1, Word16 var2)
{
    Word32 L_var_out;
    Word32 L_product;

    if ( SaturationMode ) 
    {
      L_product = L_mult (var1, var2);
      L_var_out = L_add (L_var3, L_product);
      return (L_var_out);
    }
    else
      return L_macNs(L_var3,var1,var2);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_msu                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Multiply var1 by var2 and shift the result left by 1. Subtract the 32   |
 |   bit result to L_var3 with saturation, return a 32 bit result:           |
 |        L_msu(L_var3,var1,var2) = L_sub(L_var3,L_mult(var1,var2)).         |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var3   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_msu (Word32 L_var3, Word16 var1, Word16 var2)
{
    Word32 L_var_out;
    Word32 L_product;

    if ( SaturationMode ) 
    {
      L_product = L_mult (var1, var2);
      L_var_out = L_sub (L_var3, L_product);
      return (L_var_out);
    }
    else
      return L_msuNs(L_var3,var1,var2);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_macNs                                                 |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Multiply var1 by var2 and shift the result left by 1. Add the 32 bit    |
 |   result to L_var3 without saturation, return a 32 bit result. Generate   |
 |   carry and overflow values :                                             |
 |        L_macNs(L_var3,var1,var2) = L_add_c(L_var3,L_mult(var1,var2)).     |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var3   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |                                                                           |
 |   Caution :                                                               |
 |                                                                           |
 |    In some cases the Carry flag has to be cleared or set before using     |
 |    operators which take into account its value.                           |
 |___________________________________________________________________________|
*/

static Word32 L_macNs (Word32 L_var3, Word16 var1, Word16 var2)
{
    Word32 L_var_out;

    L_var_out = L_mult (var1, var2);
    L_var_out = L_add_c (L_var3, L_var_out);
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_msuNs                                                 |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Multiply var1 by var2 and shift the result left by 1. Subtract the 32   |
 |   bit result from L_var3 without saturation, return a 32 bit result. Ge-  |
 |   nerate carry and overflow values :                                      |
 |        L_msuNs(L_var3,var1,var2) = L_sub_c(L_var3,L_mult(var1,var2)).     |
 |                                                                           |
 |   Complexity weight : 1                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var3   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |                                                                           |
 |   Caution :                                                               |
 |                                                                           |
 |    In some cases the Carry flag has to be cleared or set before using     |
 |    operators which take into account its value.                           |
 |___________________________________________________________________________|
*/

static Word32 L_msuNs (Word32 L_var3, Word16 var1, Word16 var2)
{
    Word32 L_var_out;

    L_var_out = L_mult (var1, var2);
    L_var_out = L_sub_c (L_var3, L_var_out);
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_add                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   32 bits addition of the two 32 bits variables (L_var1+L_var2) with      |
 |   overflow control and saturation; the result is set at +2147483647 when  |
 |   overflow occurs or at -2147483648 when underflow occurs.                |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    L_var2   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_add (Word32 L_var1, Word32 L_var2)
{
  Word32 L_var_out;

  if (SaturationMode ) 
  {
    L_var_out = L_var1 + L_var2;

    if (((L_var1 ^ L_var2) & MIN_32) == 0)
    {
        if ((L_var_out ^ L_var1) & MIN_32)
        {
            L_var_out = (L_var1 < 0) ? MIN_32 : MAX_32;
            Overflow = 1;
        }
    }
    return (L_var_out);
  }
  else {
    Carry = 0;
    return L_add_c(L_var1,L_var2);
  }
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_sub                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   32 bits subtraction of the two 32 bits variables (L_var1-L_var2) with   |
 |   overflow control and saturation; the result is set at +2147483647 when  |
 |   overflow occurs or at -2147483648 when underflow occurs.                |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    L_var2   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_sub (Word32 L_var1, Word32 L_var2)
{
  Word32 L_var_out;

  if ( SaturationMode )
  {
    L_var_out = L_var1 - L_var2;

    if (((L_var1 ^ L_var2) & MIN_32) != 0)
    {
        if ((L_var_out ^ L_var1) & MIN_32)
        {
            L_var_out = (L_var1 < 0L) ? MIN_32 : MAX_32;
            Overflow = 1;
        }
    }
    return (L_var_out);
  }
  else
    return L_sub_c(L_var1,L_var2);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_add_c                                                 |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Performs 32 bits addition of the two 32 bits variables (L_var1+L_var2+C)|
 |   with carry. No saturation. Generate carry and Overflow values. The car- |
 |   ry and overflow values are binary variables which can be tested and as- |
 |   signed values.                                                          |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    L_var2   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |                                                                           |
 |   Caution :                                                               |
 |                                                                           |
 |    In some cases the Carry flag has to be cleared or set before using     |
 |    operators which take into account its value.                           |
 |___________________________________________________________________________|
*/
static Word32 L_add_c (Word32 L_var1, Word32 L_var2)
{
    Word32 L_var_out;
    Word32 L_test;
    Flag carry_int = 0;

    L_var_out = L_var1 + L_var2 + Carry;

    L_test = L_var1 + L_var2;

    if ((L_var1 > 0) && (L_var2 > 0) && (L_test < 0))
    {
        Overflow = 1;
        carry_int = 0;
    }
    else
    {
        if ((L_var1 < 0) && (L_var2 < 0))
        {
            if (L_test >= 0)
	    {
                Overflow = 1;
                carry_int = 1;
	    }
            else
	    {
                Overflow = 0;
                carry_int = 1;
	    }
        }
        else
        {
            if (((L_var1 ^ L_var2) < 0) && (L_test >= 0))
            {
                Overflow = 0;
                carry_int = 1;
            }
            else
            {
                Overflow = 0;
                carry_int = 0;
            }
        }
    }

    if (Carry)
    {
        if (L_test == MAX_32)
        {
            Overflow = 1;
            Carry = carry_int;
        }
        else
        {
            if (L_test == (Word32) 0xFFFFFFFFL)
            {
                Carry = 1;
            }
            else
            {
                Carry = carry_int;
            }
        }
    }
    else
    {
        Carry = carry_int;
    }

    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_sub_c                                                 |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Performs 32 bits subtraction of the two 32 bits variables with carry    |
 |   (borrow) : L_var1-L_var2-C. No saturation. Generate carry and Overflow  |
 |   values. The carry and overflow values are binary variables which can    |
 |   be tested and assigned values.                                          |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    L_var2   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |                                                                           |
 |   Caution :                                                               |
 |                                                                           |
 |    In some cases the Carry flag has to be cleared or set before using     |
 |    operators which take into account its value.                           |
 |___________________________________________________________________________|
*/

static Word32 L_sub_c (Word32 L_var1, Word32 L_var2)
{
    Word32 L_var_out;
    Word32 L_test;
    Flag carry_int = 0;
/*
   L_var2 = (~L_var2) + 1;

   L_var_out = L_var1 + L_var2 + Carry;
   if (Carry) {
        if (L_var1 < 0 || L_var2 < 0) Carry = 1; else Carry = 0;
   } else {
        if (L_var1 < 0 && L_var2 < 0) Carry = 1; else Carry = 0;
   }
return (L_var_out);
*/

    if (Carry)
    {
        Carry = 0;
        if (L_var2 != MIN_32)
        {
            L_var_out = L_add_c (L_var1, -L_var2);
        }
        else
        {
            L_var_out = L_var1 - L_var2;
            if (L_var1 > 0L)
            {
                Overflow = 1;
                Carry = 0;
            }
        }
    }
    else
    {
        L_var_out = L_var1 - L_var2 - (Word32) 0X00000001L;
        L_test = L_var1 - L_var2;
L_var_out = L_test;

        if ((L_test < 0) && (L_var1 > 0) && (L_var2 < 0))
        {
            Overflow = 1;
            carry_int = 0;
        }
        else if ((L_test > 0) && (L_var1 < 0) && (L_var2 > 0))
        {
            Overflow = 1;
            carry_int = 1;
        }
        else if ((L_test > 0) && ((L_var1 ^ L_var2) > 0))
        {
            Overflow = 0;
            carry_int = 1;
        }
        if (L_test == MIN_32)
        {
            Overflow = 1;
            Carry = carry_int;
        }
        else
        {
            Carry = carry_int;
        }
    }
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_negate                                                |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Negate the 32 bit variable L_var1 with saturation; saturate in the case |
 |   where input is -2147483648 (0x8000 0000).                               |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_negate (Word32 L_var1)
{
    Word32 L_var_out;

    L_var_out = (L_var1 == MIN_32) ? MAX_32 : -L_var1;
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : mult_r                                                  |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Same as mult with rounding, i.e.:                                       |
 |     mult_r(var1,var2) = extract_l(L_shr(((var1 * var2) + 16384),15)) and  |
 |     mult_r(-32768,-32768) = 32767.                                        |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 mult_r (Word16 var1, Word16 var2)
{
    Word16 var_out;
    Word32 L_product_arr;

    L_product_arr = (Word32) var1 *(Word32) var2;       /* product */
    L_product_arr += (Word32) 0x00004000L;      /* round */
    L_product_arr &= (Word32) 0xffff8000L;
    L_product_arr >>= 15;       /* shift */

    if (L_product_arr & (Word32) 0x00010000L)  /* sign extend when necessary */
      L_product_arr |= (Word32) 0xffff0000L;
    var_out = saturate (L_product_arr);
    return (var_out);
}

Word16 shl_nosat (Word16 var1, Word16 var2)

{
    if (var2 <= 0)
	return (var1 >> -var2);
    else
	return (var1 << var2);
}

Word16 shr_nosat (Word16 var1, Word16 var2)

{
    if (var2 <= 0)
	return (var1 << -var2);
    else
	return (var1 >> var2);
}

Word32 L_shl_nosat (Word32 L_var1, Word16 var2)

{

    if (var2 <= 0)
	return (L_var1 >> -var2);
    else
	return (L_var1 << var2);
}

Word32 L_shr_nosat (Word32 L_var1, Word16 var2)

{
    if (var2 <= 0)
	return (L_var1 << -var2);
    else
	return (L_var1 >> var2);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_shl                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Arithmetically shift the 32 bit input L_var1 left var2 positions. Zero  |
 |   fill the var2 LSB of the result. If var2 is negative, arithmetically    |
 |   shift L_var1 right by -var2 with sign extension. Saturate the result in |
 |   case of underflows or overflows.                                        |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_shl (Word32 L_var1, Word16 var2)
{
    Word32 L_var_out;

    if (var2 <= 0)
        L_var_out = L_shr (L_var1, -var2);
    else
      for (; var2 > 0; var2--)
      {
        if (L_var1 > (Word32) 0X3fffffffL)
        {
          Overflow = 1;
          L_var_out = MAX_32;
          break;
        }
        else
        {
          if (L_var1 < (Word32) 0xc0000000L)
          {
            Overflow = 1;
            L_var_out = MIN_32;
            break;
          }
        }
        L_var1 *= 2;
        L_var_out = L_var1;
      }
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_shr                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Arithmetically shift the 32 bit input L_var1 right var2 positions with  |
 |   sign extension. If var2 is negative, arithmetically shift L_var1 left   |
 |   by -var2 and zero fill the -var2 LSB of the result. Saturate the result |
 |   in case of underflows or overflows.                                     |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var_out <= 0x7fff ffff.              |
 |___________________________________________________________________________|
*/

Word32 L_shr (Word32 L_var1, Word16 var2)
{
    Word32 L_var_out;

    if (var2 < 0)
      L_var_out = L_shl (L_var1, -var2);
    else if (var2 >= 31)
      L_var_out = (L_var1 < 0L) ? -1 : 0;
    else if (L_var1 < 0)
      L_var_out = ~((~L_var1) >> var2);
    else
      L_var_out = L_var1 >> var2;

    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : shr_r                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Same as shr(var1,var2) but with rounding. Saturate the result in case of|
 |   underflows or overflows :                                               |
 |    - If var2 is greater than zero :                                       |
 |          if (sub(shl(shr(var1,var2),1),shr(var1,sub(var2,1))))            |
 |          is equal to zero                                                 |
 |                     then                                                  |
 |                     shr_r(var1,var2) = shr(var1,var2)                     |
 |                     else                                                  |
 |                     shr_r(var1,var2) = add(shr(var1,var2),1)              |
 |    - If var2 is less than or equal to zero :                              |
 |                     shr_r(var1,var2) = shr(var1,var2).                    |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word16 shr_r (Word16 var1, Word16 var2)
{
    Word16 var_out;

    if (var2 > 15)
    {
        var_out = 0;
    }
    else
    {
        var_out = shr (var1, var2);

        if (var2 > 0)
        {
            if ((var1 & ((Word16) 1 << (var2 - 1))) != 0)
            {
                var_out++;
            }
        }
    }
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : mac_r                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Multiply var1 by var2 and shift the result left by 1. Add the 32 bit    |
 |   result to L_var3 with saturation. Round the LS 16 bits of the result    |
 |   into the MS 16 bits with saturation and shift the result right by 16.   |
 |   Return a 16 bit result.                                                 |
 |            mac_r(L_var3,var1,var2) = round(L_mac(L_var3,var1,var2))       |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var3   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 8000 <= L_var_out <= 0x0000 7fff.              |
 |___________________________________________________________________________|
*/

Word16 mac_r (Word32 L_var3, Word16 var1, Word16 var2)
{
    Word16 var_out;

    L_var3 = L_mac (L_var3, var1, var2);
    L_var3 = L_add (L_var3, (Word32) 0x00008000L);
    var_out = extract_h (L_var3);
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : msu_r                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Multiply var1 by var2 and shift the result left by 1. Subtract the 32   |
 |   bit result to L_var3 with saturation. Round the LS 16 bits of the res-  |
 |   ult into the MS 16 bits with saturation and shift the result right by   |
 |   16. Return a 16 bit result.                                             |
 |            msu_r(L_var3,var1,var2) = round(L_msu(L_var3,var1,var2))       |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var3   32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= L_var3 <= 0x7fff ffff.                 |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 8000 <= L_var_out <= 0x0000 7fff.              |
 |___________________________________________________________________________|
*/

Word16 msu_r (Word32 L_var3, Word16 var1, Word16 var2)
{
    Word16 var_out;

    L_var3 = L_msu (L_var3, var1, var2);
    L_var3 = L_add (L_var3, (Word32) 0x00008000L);
    var_out = extract_h (L_var3);
    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_deposit_h                                             |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Deposit the 16 bit var1 into the 16 MS bits of the 32 bit output. The   |
 |   16 LS bits of the output are zeroed.                                    |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= var_out <= 0x7fff 0000.                |
 |___________________________________________________________________________|
*/

Word32 L_deposit_h (Word16 var1)
{
    Word32 L_var_out;

    L_var_out = (Word32) var1 << 16;
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_deposit_l                                             |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Deposit the 16 bit var1 into the 16 LS bits of the 32 bit output. The   |
 |   16 MS bits of the output are sign extended.                             |
 |                                                                           |
 |   Complexity weight : 2                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0xFFFF 8000 <= var_out <= 0x0000 7fff.                |
 |___________________________________________________________________________|
*/

Word32 L_deposit_l (Word16 var1)
{
    Word32 L_var_out;

    L_var_out = (Word32) var1;
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_shr_r                                                 |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Same as L_shr(L_var1,var2) but with rounding. Saturate the result in    |
 |   case of underflows or overflows :                                       |
 |    - If var2 is greater than zero :                                       |
 |          if (L_sub(L_shl(L_shr(L_var1,var2),1),L_shr(L_var1,sub(var2,1))))|
 |          is equal to zero                                                 |
 |                     then                                                  |
 |                     L_shr_r(L_var1,var2) = L_shr(L_var1,var2)             |
 |                     else                                                  |
 |                     L_shr_r(L_var1,var2) = L_add(L_shr(L_var1,var2),1)    |
 |    - If var2 is less than or equal to zero :                              |
 |                     L_shr_r(L_var1,var2) = L_shr(L_var1,var2).            |
 |                                                                           |
 |   Complexity weight : 3                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= var1 <= 0x7fff ffff.                   |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= var_out <= 0x7fff ffff.                |
 |___________________________________________________________________________|
*/

Word32 L_shr_r (Word32 L_var1, Word16 var2)
{
    Word32 L_var_out;

    if (var2 > 31)
    {
        L_var_out = 0;
    }
    else
    {
        L_var_out = L_shr (L_var1, var2);
        if (var2 > 0)
        {
            if ((L_var1 & ((Word32) 1 << (var2 - 1))) != 0)
            {
                L_var_out++;
            }
        }
    }
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_abs                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |    Absolute value of L_var1; Saturate in case where the input is          |
 |                                                               -214783648  |
 |                                                                           |
 |   Complexity weight : 3                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= var1 <= 0x7fff ffff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x0000 0000 <= var_out <= 0x7fff ffff.                |
 |___________________________________________________________________________|
*/

Word32 L_abs (Word32 L_var1)
{
    Word32 L_var_out;

    if (L_var1 == MIN_32)
    {
        L_var_out = MAX_32;
    }
    else
    {
        if (L_var1 < 0)
        {
            L_var_out = -L_var1;
        }
        else
        {
            L_var_out = L_var1;
        }
    }

    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : L_sat                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |    32 bit L_var1 is set to 2147483647 if an overflow occured or to        |
 |    -2147483648 if an underflow occured on the most recent L_add_c,        |
 |    L_sub_c, L_macNs or L_msuNs operations. The carry and overflow values  |
 |    are binary values which can be tested and assigned values.             |
 |                                                                           |
 |   Complexity weight : 4                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= var1 <= 0x7fff ffff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    L_var_out                                                              |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= var_out <= 0x7fff ffff.                |
 |___________________________________________________________________________|
*/

Word32 L_sat (Word32 L_var1)
{
    Word32 L_var_out;

    L_var_out = L_var1;

    if (Overflow)
    {

        if (Carry)
        {
            L_var_out = MIN_32;
        }
        else
        {
            L_var_out = MAX_32;
        }

        Carry = 0;
        Overflow = 0;
    }
    return (L_var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : norm_s                                                  |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Produces the number of left shift needed to normalize the 16 bit varia- |
 |   ble var1 for positive values on the interval with minimum of 16384 and  |
 |   maximum of 32767, and for negative values on the interval with minimum  |
 |   of -32768 and maximum of -16384; in order to normalize the result, the  |
 |   following operation must be done :                                      |
 |                    norm_var1 = shl(var1,norm_s(var1)).                    |
 |                                                                           |
 |   Complexity weight : 15                                                  |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 0000 <= var_out <= 0x0000 000f.                |
 |___________________________________________________________________________|
*/

Word16 norm_s (Word16 var1)
{
    Word16 var_out;

    if (var1 == 0)
    {
        var_out = 0;
    }
    else
    {
        if (var1 == (Word16) 0xffff)
        {
            var_out = 15;
        }
        else
        {
            if (var1 < 0)
            {
                var1 = ~var1;
            }
            for (var_out = 0; var1 < 0x4000; var_out++)
            {
                var1 <<= 1;
            }
        }
    }

    return (var_out);
}

Word16 neg_norm_s (Word16 var1)

{
	return (-norm_s(var1));
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : div_s                                                   |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Produces a result which is the fractional integer division of var1  by  |
 |   var2; var1 and var2 must be positive and var2 must be greater or equal  |
 |   to var1; the result is positive (leading bit equal to 0) and truncated  |
 |   to 16 bits.                                                             |
 |   If var1 = var2 then div(var1,var2) = 32767.                             |
 |                                                                           |
 |   Complexity weight : 18                                                  |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    var1                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 0000 <= var1 <= var2 and var2 != 0.            |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : var1 <= var2 <= 0x0000 7fff and var2 != 0.            |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 0000 <= var_out <= 0x0000 7fff.                |
 |             It's a Q15 value (point between b15 and b14).                 |
 |___________________________________________________________________________|
*/

Word16 div_s (Word16 var1, Word16 var2)
{
    Word16 var_out = 0;
    Word16 iteration;
    Word32 L_num;
    Word32 L_denom;

    if ((var1 > var2) || (var1 < 0) || (var2 < 0))
    {
        printf ("Division Error var1=%d  var2=%d\n", var1, var2);
        return 0;
    }
    if (var2 == 0)
    {
        printf ("Division by 0, Fatal error \n");
        return 0;
    }
    if (var1 == 0)
      var_out = 0;
    else if (var1 == var2)
      var_out = MAX_16;
    else
    {
      L_num = L_deposit_l (var1);
      L_denom = L_deposit_l (var2);

      for (iteration = 0; iteration < 15; iteration++)
      {
        var_out <<= 1;
        L_num <<= 1;

        if (L_num >= L_denom)
        {
          L_num = L_sub (L_num, L_denom);
          var_out = add (var_out, 1);
        }
      }
    }

    return (var_out);
}

/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : norm_l                                                  |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Produces the number of left shifts needed to normalize the 32 bit varia-|
 |   ble L_var1 for positive values on the interval with minimum of          |
 |   1073741824 and maximum of 2147483647, and for negative values on the in-|
 |   terval with minimum of -2147483648 and maximum of -1073741824; in order |
 |   to normalize the result, the following operation must be done :         |
 |                   norm_L_var1 = L_shl(L_var1,norm_l(L_var1)).             |
 |                                                                           |
 |   Complexity weight : 30                                                  |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |             32 bit long signed integer (Word32) whose value falls in the  |
 |             range : 0x8000 0000 <= var1 <= 0x7fff ffff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 0000 <= var_out <= 0x0000 001f.                |
 |___________________________________________________________________________|
*/

Word16 norm_l (Word32 L_var1)
{
    Word16 var_out;

    if (L_var1 == 0)
    {
        var_out = 0;
    }
    else
    {
        if (L_var1 == (Word32) 0xffffffffL)
        {
            var_out = 31;
        }
        else
        {
            if (L_var1 < 0)
            {
                L_var1 = ~L_var1;
            }
            for (var_out = 0; L_var1 < (Word32) 0x40000000L; var_out++)
            {
                L_var1 <<= 1;
            }
        }
    }

    return (var_out);
}

Word16 neg_norm_l (Word32 L_var1)

{
	return (-norm_l(L_var1));
}


/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : norm_ll                                                 |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Produces the number of left shifts needed to normalize the 64 bit varia-|
 |   ble L_var1 for positive values on the interval with minimum of          |
 |   4611686018427387904 (0x4000.0000.0000.0000) and maximum of              |
 |   9223372036854775807 (0x7FFF.FFFF.FFFF.FFFF), and for negative values on |
 |	 the interval with minimum of 0xF8000.0000.0000.0000.0000 and and maximum|
 |   of 0xFC000.0000.0000.0000; in order                                     |
 |   to normalize the result, the following operation must be done :         |
 |                   norm_L_var1 = L_shl(L_var1,norm_l(L_var1)).             |
 |                                                                           |
 |   Complexity weight : 30                                                  |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    L_var1                                                                 |
 |           64 bit long signed integer (Word64) whose value falls in the    |
 |           range : 0x8000 0000 0000 0000 <= var1 <= 0x7fff ffff ffff ffff. |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    var_out                                                                |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0x0000 0000 <= var_out <= 0x0000 003f.                |
 |___________________________________________________________________________|
*/

Word16 norm_ll (Word64 L_var1)
{
    Word16 var_out;

    if (L_var1.msb == 0)		
    {
		if ( L_var1.lsb == 0 )
		{
			var_out = 0;
		}
		else
		{
			var_out = norm_l(L_var1.lsb) + 32;
		}
    }
    else 
    {
		if ( L_var1.msb == 0xffffffffL ) 
		{
            for (var_out = 32; L_var1.lsb & 0x080000000L; var_out++)
            {
                L_var1.lsb <<= 1;
            }
		}
		else
		{
			var_out = norm_l(L_var1.msb);
		}
    }

    return (var_out);
}

Word16 neg_norm_ll (Word64 L_var1)

{
	return (-norm_ll(L_var1));
}


void Set_Overflow(Word32 Value)

{
	if (Value) Overflow = 1;
	else Overflow = 0;
}

int Get_Overflow()

{
	return Overflow;
}

int Test_Overflow()

{
	return (Overflow != 0);
}

int _GetCoreId() 
{
	return 1;
}

Word32 Clip(Word32 Value, Word32 mask)

{
	return 0;
}


Word32 Extract(Word32 Val, UWord32 Mask)
{
    int Off = Mask & 0x0FFFF;
    int W = (Mask >> 16);
    int i, mask_width;
    int X;
 
    mask_width=0;
    for (i=0; i<W; i++)
      mask_width = (mask_width<<1) | 1;
  
    X = (Val >> Off) & (mask_width);
    X = (X << (32 - W)) >> (32 - W );
    return X;
}
 
UWord32 ExtractU(UWord32 Val, UWord32 Mask)
{
    int Off = Mask & 0x0FFFF;
    int W=(Mask >> 16);
    int i, mask_width;
    unsigned int X;
 
    mask_width=0;
    for (i=0; i<W; i++)
      mask_width = (mask_width<<1) | 1;
   
    X = (Val >> Off) & (mask_width);
 
    return X;
}

Word32 Extract_reg(Word32 Val, UWord32 Mask)
{
    int Off = Mask & 0x03F;
    int W = (Mask >> 8) & 0x03F;
    int i, mask_width;
    int X;
 
    mask_width=0;
    for (i=0; i<W; i++)
      mask_width = (mask_width<<1) | 1;
  
    X = (Val >> Off) & (mask_width);
    X = (X << (32 - W)) >> (32 - W );
    return X;
}
 
UWord32 ExtractU_reg(UWord32 Val, UWord32 Mask)
{
    int Off = Mask & 0x03F;
    int W=(Mask >> 7) & 0x03F;
    int i, mask_width;
    unsigned int X;
 
    mask_width=0;
    for (i=0; i<W; i++)
      mask_width = (mask_width<<1) | 1;
   
    X = (Val >> Off) & (mask_width);
 
    return X;
}


void setsat32() { SaturationMode = 1; }
void setnosat() { SaturationMode = 0; }
void set2crm() { }
void setcnvrm() { }
void * Ovl_Load_Address(void * Symb_Addr) {return Symb_Addr;}

Word16 max (Word16 var1, Word16 var2) {return (var1>var2)?var1:var2;}
UWord16 maxu (UWord16 var1, UWord16 var2) {return (var1>var2)?var1:var2;}
Word16 min (Word16 var1, Word16 var2) {return (var1<var2)?var1:var2;}
UWord16 minu (UWord16 var1, UWord16 var2) {return (var1<var2)?var1:var2;}
Word16 maxm (Word16 var1, Word16 var2)
{
	/* use of L_abs to avoid saturation of abs(-32768)*/ 
	if (L_abs(var1) < L_abs(var2))	return var2; 
	else if (var2==-var1 && var2>0)		return var2; 
	else				return var1;
}

Word32 L_max (Word32 L_var1, Word32 L_var2) {return (L_var1>L_var2)?L_var1:L_var2;}
UWord32 L_maxu (UWord32 L_var1, UWord32 L_var2) {return (L_var1>L_var2)?L_var1:L_var2;}
Word32 L_min (Word32 L_var1, Word32 L_var2) {return (L_var1<L_var2)?L_var1:L_var2;}
UWord32 L_minu (UWord32 L_var1, UWord32 L_var2) {return (L_var1<L_var2)?L_var1:L_var2;}
Word32 L_maxm (Word32 var1, Word32 var2)
{
	if (var1 == 0x80000000)			return var1;
	else if (var2 == 0x80000000)		return var2;
	else if (L_abs(var1) < L_abs(var2))	return var2; 
	else if (var2==-var1 && var2>0)		return var2;
	else					return var1;
}

/*****************************************************/
/* Double precision fractional arithmetic primitives */
/*****************************************************/

#ifndef _ENTERPRISE_C_
typedef long long etp_long_long;
#else
typedef long etp_long_long;
#endif

Word64 D_set(Word32 left , UWord32 right)
{
        Word64 target;

        target.msb = left;
        target.lsb = right;
        return target;
}

Word64 D_add (Word64 D_var1, Word64 D_var2) 
{ 
  Word64 local ; 
/*
  Carry = 0;

  local.lsb = L_add_c(D_var1.lsb, D_var2.lsb);
  local.msb = L_add_c(D_var1.msb, D_var2.msb);
*/
  local = D_ADD(D_var1, D_var2);
  if ( SaturationMode ) 
    return D_sat(local);
  else
    return local;
}

Word64 D_add_opt (Word64 D_var1, Word64 D_var2) 
{ 
  Word64 local ; 

  Carry = 0;

  local.lsb = L_add_c(D_var1.lsb, D_var2.lsb);
  local.msb = L_add_c(D_var1.msb, D_var2.msb);

  if ( SaturationMode ) 
    return D_sat(local);
  else
    return local;
}

Word64 D_sub (Word64 D_var1, Word64 D_var2) 
{
  Word64 local ;
 /* 
  Carry = 0;

  local.lsb = L_sub_c(D_var1.lsb, D_var2.lsb);
  local.msb = L_sub_c(D_var1.msb, D_var2.msb);
*/
  local = D_SUB(D_var1, D_var2);

  if ( SaturationMode ) 
    return D_sat(local);
  else
    return local;
}

Word64 D_mult_opt (Word32 L_var1, Word32 L_var2 ) 
{ 
#ifndef _ENTERPRISE_C_
  etp_long_long local;
  Word64 res; 

  local = ((etp_long_long) L_var1 * (etp_long_long) L_var2) << (etp_long_long) 1;
  res.lsb = local;
  res.msb = (long) ((etp_long_long) local >> (etp_long_long) 32);
return res;
#else
  return(D_mult(L_var1, L_var2));
#endif
}

Word32 D_mult_msp (Word32 L_var1, Word32 L_var2 ) 
{ 
#ifndef _ENTERPRISE_C_
  etp_long_long local;
  Word64 res; 

  local = ((etp_long_long) L_var1 * (etp_long_long) L_var2) << (etp_long_long) 1;
  res.lsb = local;
  res.msb = (long) ((etp_long_long) local >> (etp_long_long) 32);
return res.msb;
#else
   {
  Word64 local; 
  Word32 l1,l2;
  int    mid;

  l1 = (Word32)(unsigned short)(extract_l(L_var1)) * 
       (Word32)(extract_h(L_var2));
  l2 = (Word32)(unsigned short)(extract_l(L_var2)) * 
       (Word32)(extract_h(L_var1));
  mid = L_add(l1,l2);

  l1 = (Word32)(unsigned short)(extract_l(L_var1)) *
       (Word32)(unsigned short)(extract_l(L_var2));
  l2 = (Word32)(extract_h(L_var1)) *
       (Word32)(extract_h(L_var2));
 
  local.lsb = L_add(l1,((Word32)extract_l(mid))<<16);
  local.msb = L_add(l2, (Word32)extract_h(mid));
  
  local.msb <<= 1;
  if ( local.lsb & 0x80000000 ) local.msb += 1;
  local.lsb <<= 1;

  return local.msb; 
   }
#endif
}

Word64 D_mult (Word32 L_var1, Word32 L_var2 ) 
{ 
#ifndef _ENTERPRISE_C_
  return(D_mult_opt(L_var1, L_var2));
#else
  Word64 local; 
  Word32 l1,l2;
  int    mid;

  l1 = (Word32)(unsigned short)(extract_l(L_var1)) * 
       (Word32)(extract_h(L_var2));
  l2 = (Word32)(unsigned short)(extract_l(L_var2)) * 
       (Word32)(extract_h(L_var1));
  mid = L_add(l1,l2);

  l1 = (Word32)(unsigned short)(extract_l(L_var1)) *
       (Word32)(unsigned short)(extract_l(L_var2));
  l2 = (Word32)(extract_h(L_var1)) *
       (Word32)(extract_h(L_var2));
 
  local.lsb = L_add(l1,((Word32)extract_l(mid))<<16);
  local.msb = L_add(l2, (Word32)extract_h(mid));
  
  local.msb <<= 1;
  if ( local.lsb & 0x80000000 ) 
    local.msb += 1;
  local.lsb <<= 1;

  return local; 
#endif
}

int D_cmpeq (Word64 D_var1, Word64 D_var2) 
{ 
  return D_var1.msb == D_var2.msb && 
         D_var1.lsb == D_var2.lsb;
}

int D_cmpgt (Word64 D_var1, Word64 D_var2) 
{
  return (D_var1.msb > D_var2.msb) ||
         (D_var1.msb == D_var2.msb && D_var1.lsb > D_var2.lsb);
} 

Word64 D_sat (Word64 D_var1)
{ 
  Word64 local; 

  local = D_var1;

  if (Overflow)
  {
    if (Carry)
    {
      local.msb = MIN_32;
      local.lsb = 0;
    }
    else
    {
      local.msb = MAX_32;
      local.lsb = 0xFFFFFFFF;
    }

    Carry = 0;
    Overflow = 0;
  }
  return local; 
}

Word32 D_round (Word64 D_var1)
{
  Word64 local = {0,0x80000000};
  local = D_add(local, D_var1);

  return local.msb;
}

Word32 D_get_msb(Word64 Val) { return Val.msb; }
Word32 D_get_lsb(Word64 Val) { return Val.lsb; }

#ifdef _CW_X_SLLD_
Word32 LL_get_msb(Int64 Val)
{
	return (Val>>32);
}

UWord32 LL_get_lsb(Int64 Val)
{
	return Val;
}

Word32 Db_get_msb(double Val)
{
	union {
		Int64 L;
		double D;
	} X;
	X.D = Val;

	return (X.L>>32);
}

UWord32 Db_get_lsb(double Val)

{
	union {
		Int64 L;
		double D;
	} X;
	X.D = Val;
	return  (X.L);
}

Int64 Db_to_LL(double Val)

{
	union {
		Int64 L;
		double D;
	} X;
	X.D = Val;
	return  (X.L);
}

double LL_to_Db(Int64 Val)

{
	union {
		Int64 L;
		double D;
	} X;
	X.L = Val;
	return  (X.D);
}
#endif

Word64 D_mac(Word64 D_var3, Word32 L_var1, Word32 L_var2)
{
  return D_add(D_var3,D_mult(L_var1,L_var2));
}

Word64 D_msu(Word64 D_var3, Word32 L_var1, Word32 L_var2)
{
  return D_sub(D_var3,D_mult(L_var1,L_var2));
}

/*******************************************************/
/* Extended precision fractional arithmetic primitives */
/*******************************************************/

Word40 X_set(Word32 guard, UWord32 body)
{
  Word40 local; 

  local.ext = guard;
  local.body = body;
  return local;
}

Word40 X_extend (Word32 var1)
{
  Word40 local; 

  local.body = var1;
  local.ext = (var1>=0)?0:-1;
  return local;
}

Word16 X_extract_h (Word40 var1) { return extract_h(var1.body); }
Word16 X_extract_l (Word40 var1) { return extract_l(var1.body); }
Word32 X_trunc (Word40 var1) { return var1.body; }
Word32 X_guard (Word40 var1) { return var1.ext; }
Word16 X_round (Word40 var1)
{
    Word40 L_rounded;

    L_rounded = X_add (var1, X_extend(0x00008000L));
    return X_extract_h (L_rounded);
}

Word40 X_add (Word40 var1, Word40 var2)
{
	return X_ADD(var1, var2);
/*
  Word40 local ;

  Carry = 0;
  local.body = L_add_c(var1.body, var2.body);
  local.ext = L_add_c(var1.ext, var2.ext);

  return local;
*/
}

Word40 X_sub (Word40 var1, Word40 var2)
{
	return X_SUB(var1, var2);
/*
  Word40 local ;

  Carry = 0;
  local.body = L_sub_c(var1.body, var2.body);
  local.ext = L_sub_c(var1.ext, var2.ext);

  return local;
*/
}

Word40 X_mult (Word16 var1, Word16 var2)
{
  return X_extend(L_mult(var1,var2));
}

Word40 X_shl (Word40 var1, Word16 var2)
{
  Word40 local;
  int val ;

  if (var2 < 0) return X_shr(var1, -var2);

  if ( var2 == 0 ) {
        local.body = var1.body;
        local.ext = var1.ext;
  }
  else {
        if ( var2 < 32 )
          {
            val = var1.body >> (32-var2);
            local.body = var1.body << var2;
            local.ext = (var1.ext << var2) | val;
          }
          else
          {
            local.body  = 0;
            local.ext = var1.body << (var2-32);
          }
  }
  return local;
}

Word40 X_shr (Word40 var1, Word16 var2)
{
  Word40 local;

  local.ext = var1.ext;
  local.body = var1.body;

	if (var2 < 0) return X_shl(var1, -var2);
  while ( var2 > 0 )
  {
    local.body >>= 1;
    if ( local.ext & 1 ) 
      local.body |= 0x80000000;
    local.ext >>= 1;
    var2--;
  }
    
  return local;
}



/*___________________________________________________________________________
 |                                                                           |
 |   Function Name : X_shr_r                                                 |
 |                                                                           |
 |   Purpose :                                                               |
 |                                                                           |
 |   Same as X_shr(X_var1,var2) but with rounding. Saturate the result in    |
 |   case of underflows or overflows :                                       |
 |    - If var2 is greater than zero :                                       |
 |          if (X_sub(X_shl(X_shr(X_var1,var2),1),X_shr(X_var1,sub(var2,1))))|
 |          is equal to zero                                                 |
 |                     then                                                  |
 |                     X_shr_r(X_var1,var2) = X_shr(X_var1,var2)             |
 |                     else                                                  |
 |                     X_shr_r(X_var1,var2) = X_add(X_shr(X_var1,var2),1)    |
 |    - If var2 is less than or equal to zero :                              |
 |                     X_shr_r(X_var1,var2) = X_shr(X_var1,var2).            |
 |                                                                           |
 |   Complexity weight : 3                                                   |
 |                                                                           |
 |   Inputs :                                                                |
 |                                                                           |
 |    X_var1                                                                 |
 |             40 bit long signed integer (Word40)							 |
 |                                                                           |
 |    var2                                                                   |
 |             16 bit short signed integer (Word16) whose value falls in the |
 |             range : 0xffff 8000 <= var1 <= 0x0000 7fff.                   |
 |                                                                           |
 |   Outputs :                                                               |
 |                                                                           |
 |    none                                                                   |
 |                                                                           |
 |   Return Value :                                                          |
 |                                                                           |
 |    X_var_out                                                              |
 |             40 bit long signed integer (Word40)                           |
 |___________________________________________________________________________|
*/

Word40 X_shr_r (Word40 X_var1, Word16 var2)
{
    Word40 X_var_out;

    if (var2 > 39)
    {
        X_var_out = X_set(0,0);
    }
    else
    {
        X_var_out = X_shr (X_var1, var2);
        if (var2 > 0)
        {
			if(var2 > 32) {
			
				if ((X_var1.ext & ((char) 1 << (var2 - 32 - 1))) != 0) {
					Word40 X_var = X_set(0,1);
					X_var_out = X_add(X_var_out, X_var);
				}
				
			} else if ((X_var1.body & ((Word32) 1 << (var2 - 1))) != 0)
            {
			    Word40 X_var = X_set(0,1);
                X_var_out = X_add(X_var_out, X_var);
            }
        }
    }
    return (X_var_out);
}



Word40 X_lsl (Word40 var1, Word16 var2)
{
  if (var2 < 0) return X_lsr(var1, -var2);
  return X_shl (var1, var2);
}
Word40 X_lsr (Word40 var1, Word16 var2)
{
  Word40 local;

  local.ext = var1.ext;
  local.body = var1.body;

	if (var2 < 0) return X_lsl(var1, -var2);
  while ( var2 > 0 )
  {
    local.body >>= 1;
    if ( local.ext & 1 ) 
      local.body |= 0x80000000;
    local.ext >>= 1;

    local.ext = local.ext & 0x0000007F;
    var2--;
  }
    
  return local;
}
Word40 X_abs (Word40 var1)
{
  Word40 zero;
  zero.ext=0;
  zero.body=0;

  if(var1.ext < 0) return(X_sub(zero, var1));
  else return(var1);
  /* return ( var1.ext < 0 )? X_sub(zero, var1): var1; */
}

Word32 X_sat (Word40 var1)
{
#define MSB 0x80000000

  Word32 localPos = 0x7fffffff; 
  Word32 localNeg = 0x80000000; 

  if (( var1.ext == 0  && (var1.body & MSB) == 0 )||
      ( var1.ext == -1 && (var1.body & MSB) ))
    return X_trunc(var1);
  else if (var1.ext >= 0)
    return localPos;
  else
    return localNeg;
}

Word16 X_norm (Word40 var1)
{
  Word16 var_out;
  Word16 norm_msb = norm_s((Word16)var1.ext);
  Word16 norm_lsb = norm_l(var1.body);

  if ( var1.ext == 0 && var1.body == 0 )
    var_out = 0;
  else if (( var1.ext == 0  && (var1.body & MSB) == 0 )||
      ( var1.ext == -1 && (var1.body & MSB) ))
    var_out = norm_lsb;
  else if ( var1.ext == 0 )  /* {0,0x80000000} */ 
    var_out = -1;
  else
  {
    var_out = norm_msb-16;
    if ( var1.body & MSB ) var_out--;
  }

  return (var_out);
}


Word40 X_or (Word40 var1, Word40 var2)
{
  Word40 local; 
  
  local.body = var1.body | var2.body;
  local.ext = var1.ext | var2.ext;
  return local;
}

Word40 X_xor (Word40 var1, Word40 var2)
{
  Word40 local; 
  
  local.body = var1.body ^ var2.body;
  local.ext = var1.ext ^ var2.ext;
  return local;
}

int    X_cmpeq(Word40 var1, Word40 var2)
{ 
  return var1.ext == var2.ext && 
         var1.body == var2.body;
}

int    X_cmpgt(Word40 var1, Word40 var2) 
{
  return (var1.ext > var2.ext) ||
         (var1.ext == var2.ext && var1.body > var2.body);
} 

Word40 X_mac(Word40 X_var3, Word16 var1, Word16 var2)
{
  return X_add(X_var3,X_mult(var1,var2));
}

Word40 X_msu(Word40 X_var3, Word16 var1, Word16 var2)
{
  return X_sub(X_var3,X_mult(var1,var2));
}

Word40 X_ror (Word40 var1)
{
  Word40 local = var1;
  
  int Local_Carry = (local.body & 1) ;
  Carry = 0;
  local.body = ( (local.body >> 1) & 0x7FFFFFFF) | ((local.ext & 1)?0x80000000:0);
  if ( Carry ) 
    local.ext = (( local.ext >> 1 ) & 0x7F) | 0x80 ;
  else
    local.ext = (( local.ext >> 1 ) & 0x7F) ;
  Carry = Local_Carry;

  return local;
}

Word40 X_ror_unsafe (Word40 var1)
{
  Word40 local = var1;
  
  int Local_Carry = (local.body & 1) ;
  Carry = 0;
  local.body = ( (local.body >> 1) & 0x7FFFFFFF) | ((local.ext & 1)?0x80000000:0);
  if ( Carry ) 
    local.ext = (( local.ext >> 1 ) & 0x7F) | 0x80 ;
  else
    local.ext = (( local.ext >> 1 ) & 0x7F) ;
  Carry = Local_Carry;

  return local;
}

Word40 X_rol (Word40 var1)
{
  Word40 local = var1;
  
  int Local_Carry = (local.ext & 0x80) ;
  local.ext = ( local.ext << 1) | ((local.body & 0x80000000)?1:0);
  Carry = 0;
  if ( Carry )          
    local.body = ( local.body << 1 ) | 1 ;
  else
    local.body = ( local.body << 1 ) ;
  Carry = Local_Carry;

  return local;
}

Word40 X_rol_unsafe (Word40 var1)
{
  Word40 local = var1;
  
  int Local_Carry = (local.ext & 0x80) ;
  local.ext = ( local.ext << 1) | ((local.body & 0x80000000)?1:0);
  Carry = 0;
  if ( Carry )          
    local.body = ( local.body << 1 ) | 1 ;
  else
    local.body = ( local.body << 1 ) ;
  Carry = Local_Carry;

  return local;
}

void* __clear(void *src, unsigned int size)
{
	int i;
	char *src1 = src;
	for(i=0; i<size; i++) {
		*src1=0;
		src1++;
	}
	return src; 
}


/*****************************************************/
/* V5: Dfetch				                         */
/*****************************************************/

void _dfetch(void *mem_line) {}
void _pfetch(void *mem_line) {}
void _pfetch_imm(void *imm_address) {}

/*****************************************************/
/* V5: Syncio, Syncm Support                         */
/*****************************************************/

void _syncio() {}
void _syncm()  {}
void _syncio_barrier() {}

/*syncio load*/
char syncio_read_b(volatile char *src) { return *src; }
unsigned char syncio_read_ub(volatile unsigned char *src) { return *src; }
short syncio_read_w(volatile short *src) { return *src; }
unsigned short syncio_read_uw(volatile unsigned short *src)  { return *src; }
int syncio_read_l(volatile int *src)  { return *src; }
unsigned int syncio_read_ul(volatile unsigned int *src)  { return *src; }

/*syncm load*/
char syncm_read_b(volatile char *src)  { return *src; }
unsigned char syncm_read_ub(volatile unsigned char *src)  { return *src; }
short syncm_read_w(volatile short *src)  { return *src; }
unsigned short syncm_read_uw(volatile unsigned short *src)  { return *src; }
int syncm_read_l(volatile int *src)  { return *src; }
unsigned int syncm_read_ul(volatile unsigned int *src)  { return *src; }

/*syncio store*/
void syncio_write_b(volatile char *dst, char src) { *dst = src; }
void syncio_write_ub(volatile unsigned char *dst, unsigned char src)  { *dst = src; }
void syncio_write_w(volatile short *dst, short src)  { *dst = src; }
void syncio_write_uw(volatile unsigned short *dst, unsigned short src)  { *dst = src; }
void syncio_write_l(volatile int *dst, int src)  { *dst = src; }
void syncio_write_ul(volatile unsigned int *dst, unsigned int src)  { *dst = src; }

/*syncm store*/
void syncm_write_b(volatile char *dst, char src)  { *dst = src; }
void syncm_write_ub(volatile unsigned char *dst, unsigned char src)  { *dst = src; }
void syncm_write_w(volatile short *dst, short src)  { *dst = src; }
void syncm_write_uw(volatile unsigned short *dst, unsigned short src)  { *dst = src; }
void syncm_write_l(volatile int *dst, int src)  { *dst = src; }
void syncm_write_ul(volatile unsigned int *dst, unsigned int src)  { *dst = src; }


/* scaling*/
void force_moves_f(Word16 *ptr, Word16 src) { *ptr = src; }
void force_moves_l(long *ptr, long src) { *ptr = src; }

/* unaligned access */
long *setalign(long *src) {}
long unaligned_load(long *src) {return *src;}



/*****************************************************/
/* V5: Vector Support                                */
/*****************************************************/

typedef union {
	char ch;
	short sh;
} Endian;


/*****************************************************/
/* Pack the low part of two 32 bit vector components */
/*****************************************************/
Vector_Type32 V_pack_2w(Vector_Type32 src_msb, Vector_Type32 src_lsb)

{
	Vector_Type32 res;

	res  = (src_msb & 0x0000FFFF)<<16;
	res |=  src_lsb & 0x0000FFFF;
	return res;	
}


/*******************************************************/
/*  Pack the high part of two 32 bit vector components */
/*******************************************************/
Vector_Type32 V_pack_2fr(Vector_Type32 src_msb, Vector_Type32 src_lsb) 

{

	Vector_Type32 res;

	res  =  src_msb & 0x0FFFF0000;
	res |= (src_lsb & 0x0FFFF0000)>>16;
	return res;
}


/*****************************************************/
/* Unpack a 32 bit vector variable into two 16 bits  */ 
/* vector components and store the result in two 32  */
/* bit variables						             */
/*****************************************************/
void V_unpack_2w(Vector_Type32 src_vect, Vector_Component16 *dst_var1, Vector_Component16 *dst_var2) 

{
	*dst_var1 = src_vect & 0x0000FFFF;
	*dst_var2 = (src_vect >> 16) & 0x0000FFFF;
}


/************************************************************/
/* Load 2 signed 8 bit values into two 16-bits vector       */
/* components of a 32 bit vector variable and signed extend */
/************************************************************/
Vector_Type32 V_read2_2b(Vector_Component8 *src_mem) 

{
	Vector_Type32 res1, res2, res;
	Endian etype;

	etype.sh = 0;
	etype.ch = 1;
	/*little endian*/
	if(etype.sh == 1) {
		res1 = ((*src_mem)<<24)>>24;
		res2 = ((*((char*)src_mem+1))<<24)>>8;
	} else {
		res1 = ((*((char*)src_mem+1))<<24)>>24;
		res2 = ((*src_mem)<<24)>>8;
	}
	res  = (res1 & 0x0FFFF) | (res2 & 0xFFFF0000);
	return res;
}


/**********************************************************/
/* Load 2 unsigned 8 bit values into two 16-bits vector   */
/* components of a 32 bit vector variable and zero extend */
/**********************************************************/
Vector_Type32 V_read2_2ub(Vector_ComponentU8 *src_mem) 

{
	Vector_Type32 res1, res2, res;
	Endian etype;

	etype.sh = 0;
	etype.ch = 1;
	/*little endian*/
	if(etype.sh == 1) {
		res1 = *src_mem;
		res2 = *((char*)src_mem+1);
	} else {
		res1 = *((char*)src_mem+1);
		res2 = *src_mem;
	}
	res  = (res1 & 0x00FF) | ((res2<<16) & 0x00FF0000);
	return res;
}


/*********************************************************/
/* Store two 8 bit values from the low part of two       */
/* 16-bits vector components of a 32 bit vector variable */
/*********************************************************/
void V_write2_2b(Vector_Component8 *dst_mem, Vector_Type32 src_vect) 

{
	Endian etype;

	etype.sh = 0;
	etype.ch = 1;
	/*little endian*/
	if(etype.sh == 1) {
		*dst_mem = (char)(src_vect & 0x0FF);
		*((char*)dst_mem+1) = (char)((src_vect & 0x0FF0000)>>16);
	} else {
		*dst_mem = (char)((src_vect & 0x0FF0000)>>16);
		*((char*)dst_mem+1) = (char)(src_vect & 0x0FF);
	}
}


/************************************************************/
/* Load 4 signed 8 bit values into four 16-bits vector      */
/* components of two 32 bit vector variable and sign extend */
/************************************************************/
void V_read2_4b(Vector_Component8 * src_mem, 
				Vector_Type32 * dst_vect1, Vector_Type32 * dst_vect2) 

{
	Vector_Type32 res1, res2, res;

	*dst_vect1 = V_read2_2b(src_mem);
	*dst_vect2 = V_read2_2b((Vector_Component8*)src_mem+2);
}


/************************************************************/
/* Load 4 unsigned 8 bit values into four 16-bits vector    */
/* components of two 32 bit vector variable and zero extend */
/************************************************************/
void V_read2_4ub(Vector_ComponentU8 *src_mem, 
				Vector_Type32 *dst_vect1, Vector_Type32 *dst_vect2) 

{
	Vector_Type32 res1, res2, res;

	*dst_vect1 = V_read2_2ub(src_mem);
	*dst_vect2 = V_read2_2ub((Vector_ComponentU8*)src_mem+2);
}


/************************************************************/
/* Store four 8 bit values from the low part of four        */
/* 16-bits vector components of two 32 bit vector variables */
/************************************************************/
void V_write2_4b(Vector_Component8 *dst_mem, 
				Vector_Type32 src_vect1, Vector_Type32 src_vect2)

{
	V_write2_2b(dst_mem, src_vect1);
	V_write2_2b((Vector_Component8*)dst_mem+2, src_vect2);
}


/*************************************************************/
/* Load 8 signed 8 bit values into eight 16-bits vector      */
/* components of four 32 bit vector variable and sign extend */
/*************************************************************/
void V_read2_8b(Vector_Component8 *src_mem, 
				Vector_Type32 *dst_vect1, Vector_Type32 *dst_vect2, 
				Vector_Type32 *dst_vect3, Vector_Type32 *dst_vect4)

{
	Vector_Type32 res1, res2, res;

	*dst_vect1 = V_read2_2b(src_mem);
	*dst_vect2 = V_read2_2b((Vector_Component8*)src_mem+2);
	*dst_vect3 = V_read2_2b((Vector_Component8*)src_mem+4);
	*dst_vect4 = V_read2_2b((Vector_Component8*)src_mem+6);
}				
				

/****************************************************/
/* Load 8 unsigned 8 bit values into eight 16-bits  */
/* vector components of four 32 bit vector variable */
/****************************************************/
void V_read2_8ub(Vector_ComponentU8 *src_mem, 
				Vector_Type32 *dst_vect1, Vector_Type32 *dst_vect2, 
				Vector_Type32 *dst_vect3, Vector_Type32 *dst_vect4)

{
	Vector_Type32 res1, res2, res;

	*dst_vect1 = V_read2_2ub(src_mem);
	*dst_vect2 = V_read2_2ub((Vector_ComponentU8*)src_mem+2);
	*dst_vect3 = V_read2_2ub((Vector_ComponentU8*)src_mem+4);
	*dst_vect4 = V_read2_2ub((Vector_ComponentU8*)src_mem+6);
}


/*************************************************************/
/* Store eight 8 bit values from the low part of eight       */
/* 16-bits vector components of four 32 bit vector variables */
/*************************************************************/
void V_write2_8b(Vector_Component8 *dst_mem, 
				Vector_Type32 src_vect1, Vector_Type32 src_vect2, 
				Vector_Type32 src_vect3, Vector_Type32 src_vect4)

{
	V_write2_2b(dst_mem, src_vect1);
	V_write2_2b((char*)dst_mem+2, src_vect2);
	V_write2_2b((char*)dst_mem+4, src_vect3);
	V_write2_2b((char*)dst_mem+6, src_vect4);
}


/******************************************************/
/* Load 16 bits from memory into the low 16-bits      */
/* component of a 32 bits vector variable             */
/******************************************************/
Vector_Type32 V_read_w(Vector_Component16 *src_mem, Vector_Type32 src_vect)

{
	Vector_Type32 tmp1, tmp2;

	tmp1  = (src_vect) & 0x0FFFF0000;
	tmp2  = (*((Vector_Component16*)src_mem)) & 0x0000FFFF;
	return tmp1 | tmp2;	
}


/*****************************************************/
/* Load 16 bits from memory into the high 16-bits    */
/* component of a 32 bits vector variable            */
/*****************************************************/
Vector_Type32 V_read_fr(Vector_Component16 *src_mem, Vector_Type32 src_vect)

{
	Vector_Type32 tmp1, tmp2;

	tmp1  = (src_vect) & 0x0000FFFF;
	tmp2  = (*((Vector_Component16*)src_mem))<<16 & 0x0FFFF0000;
	return tmp1 | tmp2;	
}


/*****************************************************/
/* Swap the two 16-bit vector components of a 32 bit */
/* vector variable									 */
/*****************************************************/
Vector_Type32 V_swap(Vector_Type32 src_vect) 

{

	Vector_Type32 tmp, res;

	tmp = (src_vect & 0x0000FFFF)<<16;
	res = (src_vect & 0x0FFFF0000)>>16;
	res |= tmp;	
	return res;
}


/*****************************************************/
/* Swap the four 8-bit vector components of a 32 bit */
/* vector variable									 */
/*****************************************************/
Vector_Type32 V_swapb(Vector_Type32 src_vect) 

{

	Vector_Type32 tmp1, tmp2, tmp3, res;

	tmp1 = (src_vect & 0x00FF)<<24;
	tmp2 = (src_vect & 0x00FF00)<<8;
	tmp3 = (src_vect & 0x00FF0000)>>8;
	res  = (src_vect & 0x00FF000000)>>24;

	res = res | tmp1 | tmp2 | tmp3;	
	return res;
}



/*******************************************************/
/* Swap the four 8-bit vector components of two 16 bit */
/* vector components of a 32 bit vector variable       */
/*******************************************************/
Vector_Type32 V_swapb2(Vector_Type32 src_vect) 

{
	Vector_Type32 tmp1, tmp2, tmp3, res;

	tmp1 = (src_vect & 0x00FF)<<8;
	tmp2 = (src_vect & 0x00FF00)>>8;
	tmp3 = (src_vect & 0x00FF0000)<<8;
	res  = (src_vect & 0x00FF000000)>>8;

	res = res | tmp1 | tmp2 | tmp3;	
	return res;
}

/* performs the assignment low(dest) = low(src) */
Vector_Type32 V_tfrw_ll(Vector_Type32 dest, Vector_Type32 src) 
{
	dest &= 0xFF00;
	dest |= src & 0x00FF;
	return dest;
};

/* performs the assignment high(dest) = low(src) */
Vector_Type32 V_tfrw_lh(Vector_Type32 dest, Vector_Type32 src)	
{
	dest &= 0x00FF;
	dest |= src << 16;
	return dest;
};

/* performs the assignment low(dest) = high(src) */
Vector_Type32 V_tfrw_hl(Vector_Type32 dest, Vector_Type32 src)	
{
	dest &= 0xFF00;
	dest |= src >> 16;
	return dest;
};

/* performs the assignment high(dest) = high(src) */
Vector_Type32 V_tfrw_hh(Vector_Type32 dest, Vector_Type32 src)	
{
	dest &= 0x00FF;
	dest |= src & 0xFF00;
	return dest;
};

/*********************************************************/
/* combine src1 and src2 in result such that:            */
/*                                                       */
/* low(result) == low(src1)                              */
/* high(result) == high(src2)                            */
/*********************************************************/
Vector_Type32 V_pack_ll_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	tmp = src_vect1 & 0x0FFFF;
	res = src_vect2 & 0x0FFFF0000;
	res  = res | tmp;
	return res;
}


/*********************************************************/
/* combine src1 and src2 in result such that:            */
/*                                                       */
/* low(result) == high(src2)                             */
/* high(result) == low(src1)                             */
/*********************************************************/
Vector_Type32 V_pack_lh_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	tmp = (src_vect1 & 0x0FFFF)<<16;
	res = (src_vect2 & 0xFFFF0000)>>16;
	res  = res | tmp;
	return res;
}


/*********************************************************/
/* combine src1 and src2 in result such that:            */
/*                                                       */
/* low(result) == high(src1)                             */
/* high(result) == low(src2)                             */
/*********************************************************/
Vector_Type32 V_pack_hl_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	tmp = (src_vect1 & 0x0FFFF0000)>>16;
	res = (src_vect2 & 0xFFFFFF)<<16;
	res  = res | tmp;
	return res;
}


/*********************************************************/
/* combine src1 and src2 in result such that:            */
/*                                                       */
/* low(result) == low(src2)                              */
/* high(result) == high(src1)                            */
/*********************************************************/
Vector_Type32 V_pack_hh_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	tmp = src_vect1 & 0xFFFF0000;
	res = src_vect2 & 0x0FFFF;
	res  = res | tmp;
	return res;
}


/*************************************************************/
/* Add the low 16-bit component of a 32 bits vector variable */
/* with the low 16-bits component of second 32 bits vector   */
/* variable (the result)                                     */
/*************************************************************/
Vector_Type32 V_add_w_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	tmp = src_vect1 & 0x0FFFF0000;
	res = ((src_vect1 & 0x0FFFF) + (src_vect2 & 0x0FFFF)) & 0x0FFFF;
	res  = res | tmp;
	return res;
}


/*************************************************************/
/* Add the low 16-bit component of a 32 bits vector variable */
/* with the high 16-bits component of second 32 bits vector  */
/* variable (the result)                                     */
/*************************************************************/
Vector_Type32 V_add_w_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	res = src_vect1 & 0x0FFFF;
	tmp = (src_vect1 & 0x0FFFF0000)>>16;
	tmp = ((tmp + (src_vect2 & 0x0FFFF)) & 0x0FFFF)<<16;
	res  = res | (tmp & 0x0FFFF0000);
	return res;
}


/**************************************************************/
/* Add the high 16-bit component of a 32 bits vector variable */
/* with the low 16-bits component of second 32 bits vector    */
/* variable (the result)                                      */
/**************************************************************/
Vector_Type32 V_add_w_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	res = src_vect1 & 0x0FFFF0000;
	tmp = (src_vect2 & 0x0FFFF0000)>>16;
	tmp = ((src_vect1 & 0x0FFFF) + tmp) & 0x0FFFF;
	res  = res | tmp;
	return res;
}


/**************************************************************/
/* Add the high 16-bit component of a 32 bits vector variable */
/* with the high 16-bits component of second 32 bits vector   */
/* variable (the result)                                      */
/**************************************************************/
Vector_Type32 V_add_w_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	res = src_vect1 & 0x0FFFF;
	tmp = ((src_vect1 & 0x0FFFF0000)>>16) + ((src_vect2 & 0x0FFFF0000)>>16);
	tmp = (tmp<<16) & 0x0FFFF0000;
	res  = res | tmp;
	return res;
}


/*******************************************************************/
/* Substract the low 16-bit component of a 32 bits vector variable */
/* from the low 16-bits component of second 32 bits vector         */
/* variable (the result)                                           */
/*******************************************************************/
Vector_Type32 V_sub_w_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	tmp = src_vect1 & 0x0FFFF0000;
	res = ((src_vect1 & 0x0FFFF) - (src_vect2 & 0x0FFFF)) & 0x0FFFF;
	res  = res | tmp;
	return res;
}


/*******************************************************************/
/* Substract the low 16-bit component of a 32 bits vector variable */
/* from the high 16-bits component of second 32 bits vector        */
/* variable (the result)                                           */
/*******************************************************************/
Vector_Type32 V_sub_w_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	res = src_vect1 & 0x0FFFF;
	tmp = (src_vect1 & 0x0FFFF0000)>>16;
	tmp = ((tmp - (src_vect2 & 0x0FFFF)) & 0x0FFFF)<<16;
	res  = res | (tmp & 0x0FFFF0000);
	return res;
}


/********************************************************************/
/* Substract the high 16-bit component of a 32 bits vector variable */
/* from the low 16-bits component of second 32 bits vector          */
/* variable (the result)                                            */
/********************************************************************/
Vector_Type32 V_sub_w_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	res = src_vect1 & 0x0FFFF0000;
	tmp = (src_vect2 & 0x0FFFF0000)>>16;
	tmp = ((src_vect1 & 0x0FFFF) - tmp) & 0x0FFFF;
	res  = res | tmp;
	return res;
}


/********************************************************************/
/* Substract the high 16-bit component of a 32 bits vector variable */
/* from the high 16-bits component of second 32 bits vector         */
/* variable (the result)                                            */
/********************************************************************/
Vector_Type32 V_sub_w_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp, res;

	res = src_vect1 & 0x0FFFF;
	tmp = ((src_vect1 & 0x0FFFF0000)>>16) - ((src_vect2 & 0x0FFFF0000)>>16);
	tmp = (tmp<<16) & 0x0FFFF0000;
	res  = res | tmp;
	return res;
}


/******************************************************/
/* Add two 32 bits vector  variables, containing each */
/* 2 16-bits vector components						  */
/******************************************************/
Vector_Type32 V_sod2aaii(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) + (src_vect2 & 0x0FFFF)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) + (src_vect2 & 0x0FFFF0000)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/******************************************************************/
/* Add the high part of a 32 bits vector variable by the low part */
/* of a 32 bits vector variable in the low part of the 32 bits    */
/* vector variable result. Add the low part of the first 32 bits  */
/* vector variable by the high part of a 32 bits vector variable  */
/* in the high part of the 32 bits vector variable result         */
/******************************************************************/
Vector_Type32 V_sod2aaxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) + ((src_vect2 & 0x0FFFF0000)>>16)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) + ((src_vect2 & 0x0FFFF)<<16)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/***************************************************************/
/* Add the high part of a 32 bits vector variable by the high  */
/* part of a 32 bits vector variable in the high part of the   */
/* 32 bits vector variable result. Subtract the low part of    */
/* the first 32 bits vector variable from the low part of a 32 */
/* bits vector variable in the low part of the 32 bits vector  */
/* variable result		                                       */
/***************************************************************/
Vector_Type32 V_sod2asii(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) - (src_vect2 & 0x0FFFF)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) + (src_vect2 & 0x0FFFF0000)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/*******************************************************************/
/* Add the high part of a 32 bits vector variable by the low part  */
/* of a 32 bits vector variable in the low part of the 32 bits     */
/* vector variable result. Subtract the low part of the first 32   */
/* bits vector variable from the high part of a 32 bits vector     */
/* variable in the high part of the 32 bits vector variable result */
/*******************************************************************/
Vector_Type32 V_sod2asxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) + ((src_vect2 & 0x0FFFF0000)>>16)) & 0x0FFFF;
	tmp2 = (( src_vect1 & 0x0FFFF0000) - ((src_vect2 & 0x0FFFF)<<16)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/******************************************************************/
/* Subtract the high part of a 32 bits vector variable from the   */
/* high part of a 32 bits vector variable in the high part of the */
/* 32 bits vector variable result. Add the low part of the first  */
/* 32 bits vector variable by the low part of a 32 bits vector    */
/* variable in the low part of the 32 bits vector variable result */
/******************************************************************/
Vector_Type32 V_sod2saii(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) + (src_vect2 & 0x0FFFF)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) - (src_vect2 & 0x0FFFF0000)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/********************************************************************/
/* Subtract the high part of a 32 bits vector variable from the low */
/* part of a 32 bits vector variable in the low part of the 32 bits */
/* vector variable result. Add the low part of the first 32 bits    */
/* vector variable by the high part of a 32 bits vector variable in */
/* the high part of the 32 bits vector variable result              */
/********************************************************************/
Vector_Type32 V_sod2saxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) - ((src_vect2 & 0x0FFFF0000)>>16)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) + ((src_vect2 & 0x0FFFF)<<16)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/**********************************************************************/
/* Subtract the high part of a 32 bits vector variable from the high  */
/* part of a 32 bits vector variable in the high part of the 32 bits  */
/* vector variable result. Subtract the low part of the first 32 bits */ 
/* vector variable from the low part of a 32 bits vector variable in  */
/* the low part of the 32 bits vector variable result                 */
/**********************************************************************/
Vector_Type32 V_sod2ssii(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) - (src_vect2 & 0x0FFFF)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) - (src_vect2 & 0x0FFFF0000)) & 0x0FFFF0000;
	return  tmp1 | tmp2;
}


/*************************************************************************/
/* Subtract the high part of a 32 bits vector variable from the low part */
/* of a 32 bits vector variable in the low part of the 32 bits vector    */
/* variable result. Subtract the low part of the first 32 bits vector    */
/* variable from the high part of a 32 bits vector variable in the high  */
/* part of the 32 bits vector variable result                            */
/*************************************************************************/
Vector_Type32 V_sod2ssxx(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) - ((src_vect2 & 0x0FFFF0000)>>16)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) - ((src_vect2 & 0x0FFFF)<<16)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/*****************************************************/
/*  Add two vector variables, containing each 2      */
/* 16-bits vector components						 */
/*****************************************************/
Vector_Type32 V_add2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect2 & 0x0FFFF) + (src_vect1 & 0x0FFFF)) & 0x0FFFF;
	tmp2 = ((src_vect2 & 0x0FFFF0000) + (src_vect1 & 0x0FFFF0000)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/*****************************************************/
/* Subtract two vector variables, containing each 2  */
/* 16-bits vector components						 */
/*****************************************************/
Vector_Type32 V_sub2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((src_vect1 & 0x0FFFF) - (src_vect2 & 0x0FFFF)) & 0x0FFFF;
	tmp2 = ((src_vect1 & 0x0FFFF0000) - (src_vect2 & 0x0FFFF0000)) & 0x0FFFF0000;
	return tmp1 | tmp2;
}


/*****************************************************/
/* Compute the absolute value of the two 16-bits	 */
/* vector components of a 32 bit vector variable     */
/*****************************************************/
Vector_Type32 V_abs2(Vector_Type32 src_vect) 

{
	Vector_Component16 tmp1, tmp2;
	
	tmp1 = (Vector_Component16)src_vect;
	tmp2 = (Vector_Component16)(src_vect>>16);

	return abs(tmp1) | (abs(tmp2)<<16);
}


/*****************************************************/
/* Negate the two 16-bits vector components of a 32  */
/* bit vector variable								 */
/*****************************************************/
Vector_Type32 V_neg2(Vector_Type32 src_vect) 

{
	return ((-(src_vect >> 16)) << 16) | ((-src_vect) & 0xFFFF);
}


/*****************************************************/
/* Performs max on two vector variables, containing  */
/* each 2 16-bits vector components					 */
/*****************************************************/
Vector_Type32 V_max2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((short) src_vect1 > (short) src_vect2) ? (src_vect1 & 0x0FFFF):( src_vect2 & 0x0FFFF);
	tmp2 = ((short) (src_vect1 >> 16) > (short) (src_vect2 >> 16)) ? (src_vect1 & 0xFFFF0000):( src_vect2 & 0xFFFF0000);
	return tmp1 | tmp2;
}


/*****************************************************/
/* Performs min on two vector variables, containing  */
/* each 2 16-bits vector components					 */
/*****************************************************/
Vector_Type32 V_min2(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = ((short) src_vect1 < (short) src_vect2) ? (src_vect1 & 0x0FFFF):( src_vect2 & 0x0FFFF);
	tmp2 = ((short) (src_vect1 >> 16) < (short) (src_vect2 >> 16)) ? (src_vect1 & 0xFFFF0000):( src_vect2 & 0xFFFF0000);

	return tmp1 | tmp2;
}


/*********************************************************/
/* Perform arithmetic shift left by 1 on the two         */
/* 16-bits vector components of a 32 bit vector variable */
/*********************************************************/
Vector_Type32 V_asl2(Vector_Type32 src_vect) 

{ 
	return (((src_vect>>16)<<1) << 16) | ((src_vect<<1) & 0x0FFFF);
}


/*****************************************************/
/* Perform arithmetic shift lefton the two 16-bits   */
/* vector components of a 32 bit vector variable     */
/* - use unsigned 4 bits immediate					 */
/*****************************************************/
Vector_Type32 V_asll2(Vector_Type32 src_vect, int val) 

{
	Vector_Type32 res, tmp;
	int imm, i;

	if ((imm = val & 0x01F)>16) {
	
		imm = (~imm & 0x0F) + 1;
		res = src_vect;
		for (i=0; i<imm; i++) 
			res = V_asr2(res);
	} else {
		tmp = ((src_vect >> 16) << imm) << 16;
		res = (src_vect << imm) & 0x0FFFF;
		res = res | tmp;
	}
	return res;
}


/*********************************************************/
/* Perform arithmetic shift right by 1 on the two        */
/* 16-bits vector components of a 32 bit vector variable */
/*********************************************************/
Vector_Type32 V_asr2(Vector_Type32 src_vect)  

{
	Vector_Type32 tmp1, tmp2;
	int bit;

	tmp1 = src_vect >> 16;
	bit  = tmp1 & 0x08000;
	tmp1 = ((tmp1 >> 1) | bit) << 16;

	tmp2 = src_vect & 0x0FFFF;
	bit  = tmp2 & 0x08000;
	tmp2 = ((tmp2 >> 1) | bit);

	return tmp1 | tmp2;
}


/*****************************************************/
/* Perform arithmetic shift right on the two 16-bits */
/* vector components of a 32 bit vector variable     */
/* - use unsigned 4 bits immediate					 */
/*****************************************************/
Vector_Type32 V_asrr2(Vector_Type32 src_vect, int val)  

{
	Vector_Type32 res, tmp;
	int imm, i;

	res = src_vect;
	if ((imm = val & 0x01F)>16) {
		imm = (~imm & 0x0F) + 1;
		tmp = ((src_vect >> 16) << imm) << 16;
		res = (src_vect << imm) & 0x0FFFF;
		res = res | tmp;
	} else {
		for (i=0; i<imm; i++)
			res = V_asr2(res);
	}
	return res;
}


/********************************************************/
/* Perform logical shift left on the two 16-bits vector */
/* components of a 32 bit vector variable			    */
/* - use unsigned 4 bits immediate					    */
/********************************************************/
Vector_Type32 V_lsll2(Vector_Type32 src_vect, int val)  

{
	Vector_Type32 tmp1, tmp2;
	int imm, i;

	if ((imm = val & 0x01F)>16) {
		imm = (~imm & 0x0F) + 1;
		tmp1 = (((src_vect >> 16) & 0x0FFFF) >> imm) << 16;
		tmp2 = ((src_vect & 0x0FFFF) >> imm) & 0x0FFFF;
	} else {
		tmp1 = (((src_vect >> 16) & 0x0FFFF) << imm) << 16;
		tmp2 = ((src_vect & 0x0FFFF) << imm) & 0x0FFFF;
	}
	return tmp1 | tmp2;
}


/*********************************************************/
/* Perform logical shift right by 1 on the two           */
/* 16-bits vector components of a 32 bit vector variable */
/*********************************************************/
Vector_Type32 V_lsr2(Vector_Type32 src_vect) 

{
	return ((((src_vect>>16) & 0x0FFFF)>>1)<<16) | ((src_vect&0xFFFF)>>1);
}


/*********************************************************/
/* Perform logical shift right on the two 16-bits vector */
/* components of a 32 bit vector variable                */
/* - use unsigned 4 bits immediate					     */
/*********************************************************/
Vector_Type32 V_lsrr2(Vector_Type32 src_vect, int val)

{
	Vector_Type32 tmp1, tmp2;
	int imm, i;

	if ((imm = val & 0x01F)>16) {
		imm = (~imm & 0x0F) + 1;
		tmp1 = ((src_vect >> 16) << imm) << 16;
		tmp2 = (src_vect << imm) & 0x0FFFF;
	} else {
		tmp1 = (((src_vect >> 16) & 0x0FFFF) >> imm) << 16;
		tmp2 = (src_vect & 0x0FFFF) >> imm;
	}
	return tmp1 | tmp2;
}


/*******************************************************/
/* Saturate two 16-bits vector components of a 32-bits */
/* vector variable to two unsigned 8-bits values       */
/*******************************************************/
Vector_Type32 V_satu2b(Vector_Type32 src_vect) 

{
	Vector_Type32 tmp1, tmp2;

	tmp1 = (short)(src_vect & 0x0FFFF);
	if( tmp1 > 0x0FF)
		tmp1 = 0x0FF;
	else if ( tmp1 < 0x0)
		tmp1 = 0x0;
		
	tmp2 = (short)((src_vect >> 16) & 0x0FFFF);
	if( tmp2 > 0x0FF)
		tmp2 = 0x0FF;
	else if ( tmp2 < 0x0)
		tmp2 = 0x0;
	tmp2 <<= 16;
	return (tmp2 | tmp1);
}



/*****************************************************/
/* Perform average on two 32-bits vector variables,  */
/* containing each 2 8-bits vector components        */
/*****************************************************/
Vector_Type32 V_avgu4(Vector_Type32 src_vect1, Vector_Type32 src_vect2) 

{
	Vector_Type32 res;
	Vector_ComponentU8 tmp1, tmp2, tmp[4];

	tmp1 = src_vect1;
	tmp2 = src_vect2;
	res  = ((tmp1+tmp2+1) >> 1) & 0x0FF; 
	
	tmp1 = (src_vect1) >> 8;
	tmp2 = (src_vect2) >> 8;
	res  |= (((tmp1+tmp2+1) >> 1) << 8) & 0x0FF00; 

	tmp1 = (src_vect1) >> 16;
	tmp2 = (src_vect2) >> 16;
	res  |= (((tmp1+tmp2+1) >> 1) << 16) & 0x0FF0000; 

	tmp1 = (src_vect1) >> 24;
	tmp2 = (src_vect2) >> 24;
	
	res  |= (((tmp1+tmp2+1) >> 1) << 24) & 0x0FF000000; 

	return res;
}


/*************************************************************/
/* Perform multiply on 2 8-bits components (signed/unsigned) */
/* of two 32-bits vector variables in the two 20-bits vector */
/* components of a 40-bits vector variable                   */
/*************************************************************/
Word40 V_impysu2(Vector_Type32 src_vect1, Vector_Type32 src_vect2)

{
	Word40 res = {0, 0};
	Vector_Component8  tmp1, tmp3;
	Vector_ComponentU8 tmp2;
	int src1, src2;

	tmp1 = src_vect2 & 0xFF;
	tmp2 = src_vect1 & 0xFF;
	
	res = put_Low20Component(res, tmp1 * tmp2);		

	tmp1 = (src_vect2 >> 16) & 0x0FF;
	tmp2 = (src_vect1 >> 16) & 0x0FF;
	res = put_High20Component(res, tmp1 * tmp2);		
	return res;
}



/*************************************************************/
/* Perform clip on 2 20-bits components of a 40-bits vector  */
/* variables in the two 20-bits vector						 */
/*************************************************************/
Word40 V_clip2(Word40 src_vect, int imm)

{ 
  Word40 res = {0,0}; 
  Vector_Component20 tmp1, tmp2;
  int i, out_bit = 1, out1, out2;
  
  /*check imm*/
  if(imm>0xF || imm<0) return res;  
  if(!imm) return src_vect;
  
  tmp1 = get_Low20Component(src_vect);
  tmp2 = get_High20Component(src_vect);

  /*find out the out bit*/
  for(i=1; i<imm; i++)
	out_bit = out_bit << 1;
  out1 = tmp1 & out_bit;
  out2 = tmp2 & out_bit;

  /*sign extend from 20 to 32 bits*/
  if( tmp1 & 0x080000) tmp1 |= 0xFFF00000;
  if( tmp2 & 0x080000) tmp2 |= 0xFFF00000;
 
  tmp1 = tmp1 >> imm;
  tmp2 = tmp2 >> imm;
  
  if(out1) tmp1 = tmp1+1;
  if(out2) tmp2 = tmp2+1;
  
  if(tmp1 > 0x000FF) tmp1 = 0x000FF;
  else if (tmp1 & 0x010000) tmp1 = 0;
  
  if(tmp2 > 0x000FF) tmp2 = 0x000FF;
  else if (tmp2 & 0x010000) tmp2 = 0;

  res = put_Low20Component(res, tmp1);
  res = put_High20Component(res, tmp2);
  return res; 
}


/*************************************************************/
/* Perform multiply on 2 8-bits components (signed/unsigned) */
/* of two 32-bits vector variables and accumulate with two   */
/* 20-bits vector components of a 40-bits vector variable    */
/*************************************************************/
Word40 V_imacsu2(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Word40 src_vect3)

{
	return V_add2_20Component(src_vect3, V_impysu2(src_vect1, src_vect2));
}


/************************************************************/
/* Performs a subtraction between the four 8-bit components */
/* of a 32-bit vector variable from the four 8 bit          */
/* components of a second 32-bit vector variable. The       */
/* absolute value of each subtraction is added to the low   */
/* 16 bits component of a third 32-bit vector variable      */
/************************************************************/
Vector_Type32 V_sad4(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3) 

{

	Vector_Type32 tmp;
	
	tmp =	abs( (src_vect2 & 0xFF) - (src_vect1 & 0xFF) ) +
			abs( (((src_vect2 & 0xFF00)>>8) - ((src_vect1 & 0xFF00)>>8)) ) +
			abs( (((src_vect2 & 0xFF0000)>>16) - ((src_vect1 & 0xFF0000)>>16)) ) +
			abs( (((src_vect2 & 0x0FF000000)>>24) - ((src_vect1 &0x0FF000000)>>24)) );
			
	return (((tmp & 0x0FFFF) + (src_vect3 & 0x0FFFF)) & 0x0FFFF);

}


Vector_Component16 get_Low16Component(Vector_Type32 var)

{
	return extract_l(var);
}

Vector_Component16 get_High16Component(Vector_Type32 var)

{
	return extract_h(var);
}


/*mpy instructions*/
Vector_Component16 V_mult_hh(Vector_Type32 var1, Vector_Type32 var2) 

{
	Vector_Component16 comp_var1, comp_var2;

    comp_var1 = get_High16Component(var1);
    comp_var2 = get_High16Component(var2);

	return mult(comp_var1, comp_var2);
}

Vector_Type32 V_L_mult_hh(Vector_Type32 var1, Vector_Type32 var2)

{
	Vector_Component16 comp_var1, comp_var2;
	
    comp_var1 = get_High16Component(var1);
    comp_var2 = get_High16Component(var2);
	
	return L_mult(comp_var1, comp_var2);
}

Vector_Type40 V_X_mult_hh(Vector_Type32 var1, Vector_Type32 var2) 

{
	Vector_Component16 comp_var1, comp_var2;
	
    comp_var1 = get_High16Component(var1);
    comp_var2 = get_High16Component(var2);
    
	return X_mult(comp_var1, comp_var2);
}


Vector_Component16 V_mult_lh(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);
    comp_var2 = get_High16Component(var2);
    
    return mult(comp_var1, comp_var2);    
}

Vector_Type32 V_L_mult_lh(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);
    comp_var2 = get_High16Component(var2);
    
    return L_mult(comp_var1, comp_var2);    
}


Vector_Type40 V_X_mult_lh(Vector_Type32 var1, Vector_Type32 var2)

{
  return X_extend(V_L_mult_lh(var1,var2));
}

Vector_Component16 V_mult_hl(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);
    comp_var2 = get_Low16Component(var2);
    
    return mult(comp_var1, comp_var2);    
}


Vector_Type32 V_L_mult_hl(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);
    comp_var2 = get_Low16Component(var2);
    
    return L_mult(comp_var1, comp_var2);    
}


Vector_Type40 V_X_mult_hl(Vector_Type32 var1, Vector_Type32 var2)

{
  return X_extend(V_L_mult_hl(var1,var2));
}

Vector_Component16 V_mult_ll(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);
    comp_var2 = get_Low16Component(var2);   

    return mult(comp_var1, comp_var2);    
}

Vector_Type32 V_L_mult_ll(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);   
    comp_var2 = get_Low16Component(var2);

    return L_mult(comp_var1, comp_var2);    
}

Vector_Type40 V_X_mult_ll(Vector_Type32 var1, Vector_Type32 var2)

{
  return X_extend(V_L_mult_ll(var1,var2));
}

/*mpyr instructions*/
Vector_Component16 V_mult_r_hh(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return mult_r(comp_var1, comp_var2);    
}


Vector_Component16 V_mult_r_lh(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2, var_out;
    Vector_Type32 L_product_arr;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_High16Component(var2);

    return mult_r(comp_var1, comp_var2);    
}


Vector_Component16 V_mult_r_hl(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2, var_out;
    Vector_Type32 L_product_arr;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_Low16Component(var2);

    return mult_r(comp_var1, comp_var2);    
}


Vector_Component16 V_mult_r_ll(Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2, var_out;
    Vector_Type32 L_product_arr;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_Low16Component(var2);

    return mult_r(comp_var1, comp_var2);    
}


Vector_Type32 V_L_mac_hh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return L_mac(L_var3, comp_var1, comp_var2);
}

Vector_Type40 V_X_mac_hh(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_add(X_var3,V_X_mult_hh(var1,var2));
}

Vector_Type32 V_L_msu_hh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return L_msu(L_var3, comp_var1, comp_var2);
}

Vector_Type40 V_X_msu_hh(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_sub(X_var3,V_X_mult_hh(var1,var2));
}

Vector_Type32 V_L_mac_hl(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return L_mac(L_var3, comp_var1, comp_var2);
}


Vector_Type40 V_X_mac_hl(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_add(X_var3,V_X_mult_hl(var1,var2));
}

Vector_Type32 V_L_msu_hl(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return L_msu(L_var3, comp_var1, comp_var2);
}

Vector_Type40 V_X_msu_hl(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_sub(X_var3,V_X_mult_hl(var1,var2));
}

Vector_Type32 V_L_mac_lh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return L_mac(L_var3, comp_var1, comp_var2);
}

Vector_Type40 V_X_mac_lh(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_add(X_var3,V_X_mult_lh(var1,var2));
}

Vector_Type32 V_L_msu_lh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return L_msu(L_var3, comp_var1, comp_var2);
}

Vector_Type40 V_X_msu_lh(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_sub(X_var3,V_X_mult_lh(var1,var2));
}

Vector_Type32 V_L_mac_ll(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return L_mac(L_var3, comp_var1, comp_var2);
}

Vector_Type40 V_X_mac_ll(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_add(X_var3,V_X_mult_ll(var1,var2));
}

Vector_Type32 V_L_msu_ll(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return L_msu(L_var3, comp_var1, comp_var2);
}


Vector_Type40 V_X_msu_ll(Vector_Type40 X_var3, Vector_Type32 var1, Vector_Type32 var2)

{
  return X_sub(X_var3,V_X_mult_ll(var1,var2));
}

/*macr instructions*/
Vector_Component16 V_mac_r_hh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return mac_r(L_var3, comp_var1, comp_var2);
}


Vector_Component16 V_msu_r_hh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return msu_r(L_var3, comp_var1, comp_var2);
}

Vector_Component16 V_mac_r_hl(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return mac_r(L_var3, comp_var1, comp_var2);
}


Vector_Component16 V_msu_r_hl(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_High16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return msu_r(L_var3, comp_var1, comp_var2);
}

Vector_Component16 V_mac_r_lh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return mac_r(L_var3, comp_var1, comp_var2);
}


Vector_Component16 V_msu_r_lh(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_High16Component(var2);
    
    return msu_r(L_var3, comp_var1, comp_var2);
}


Vector_Component16 V_mac_r_ll(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return mac_r(L_var3, comp_var1, comp_var2);
}


Vector_Component16 V_msu_r_ll(Vector_Type32 L_var3, Vector_Type32 var1, Vector_Type32 var2)

{
    Vector_Component16 comp_var1, comp_var2;
    
    comp_var1 = get_Low16Component(var1);       
    comp_var2 = get_Low16Component(var2);
    
    return msu_r(L_var3, comp_var1, comp_var2);
}

/*****************************************************/
/* Initialize a 20-bit vector component              */
/*****************************************************/
Vector_Component20 init_20Component(int value)

{
	return value & 0x0FFFFF;
}


/*****************************************************/
/* Get the low 20-bit vector component of a 40 bit   */
/* vector variable									 */
/*****************************************************/
Vector_Component20 get_Low20Component(Word40 src_vect)

{
	return ((src_vect.body & 0x0FFFF) | ((src_vect.ext & 0x0F) << 16)) & 0x0FFFFF;
}


/*****************************************************/
/* Get high low 20-bit vector component of a 40 bit  */
/* vector variable									 */
/*****************************************************/
Vector_Component20 get_High20Component(Word40 src_vect)

{
	return (((src_vect.body >> 16) & 0x0FFFF) | (((src_vect.ext >> 4) & 0x0F) << 16)) & 0x0FFFFF;
}


/*****************************************************/
/* Set the low 20-bit vector component of a 40 bit   */
/* vector variable using a 20-bit vector component   */
/*****************************************************/
Word40 put_Low20Component(Word40 src_vect, Vector_Component20 comp)

{
	Word40 res;
	
	res.body = src_vect.body & 0x0FFFF0000;	
	
	res.body |= comp & 0x0FFFF;
	res.ext  = src_vect.ext & 0x0F0;
	res.ext  |= ((comp >> 16) & 0x0F);
	return res;
}


/*****************************************************/
/* Set the high 20-bit vector component of a 40 bit  */
/* vector variable using a 20-bit vector component   */
/*****************************************************/
Word40 put_High20Component(Word40 src_vect, Vector_Component20 comp)

{
	Word40 res;
	
	res.body = src_vect.body & 0x0FFFF;	
	res.body |= ((comp << 16) & 0x0FFFF0000);
	res.ext  = src_vect.ext & 0x0F;
	res.ext  |= ((comp >> 12) & 0x0F0);
	return res;
}


/*****************************************************/
/* Add two 20-bit vector components of a 40 bit      */
/* vector variable                                   */
/*****************************************************/
Word40 V_add2_20Component(Word40 src_vect1, Word40 src_vect2)

{
	Vector_Component20 tmp1, tmp2;
	Word40 res;
	
	tmp1 = get_Low20Component(src_vect1);
	tmp2 = get_Low20Component(src_vect2);

	res = put_Low20Component(res, tmp1 + tmp2);

	tmp1 = get_High20Component(src_vect1);
	tmp2 = get_High20Component(src_vect2);
	
	res = put_High20Component(res, tmp1 + tmp2);
	return res;
}


/* End V5 Vector Support */


/*****************************************************/
/* Other primitives                                  */
/*****************************************************/

Word32 L_ror (Word32 L_var1)
{
  unsigned long val = (unsigned long) L_var1;

  if ( val & 1 )  
    val = ( val >> 1 ) | 0x80000000;
  else
    val = ( val >> 1 );
  
  return (Word32)val;
}

Word32 L_rol (Word32 var1)
{
  unsigned long val = (unsigned long) var1;

  if ( val & 0x80000000 )
    val = ( val << 1) | 1;
  else
    val = ( val << 1 );
  
  return (Word32)val;
}

Word32 mpyuu( Word32 var1, Word32 var2 ) 
{ 
  Word32 L_var_out;

  L_var_out = (Word32)(unsigned short)(extract_l(var1)) * 
              (Word32)(unsigned short)(extract_l(var2));
  L_var_out *= 2;

  return L_var_out;
}
 
Word32 mpyus( Word32 var1, Word32 var2 ) 
{ 
  Word32 L_var_out;

  L_var_out = (Word32)(unsigned short)(extract_l(var1)) * 
              (Word32)(extract_h(var2));
  L_var_out *= 2;

  return L_var_out;
}

Word32 mpyus_shr16(Word32 var1, Word16 var2)

{
  Word32 L_var_out;

  L_var_out = (Word32)(unsigned short)(extract_l(var1)) * (Word32) var2;
  L_var_out = L_var_out >> 15;

  return L_var_out;
}

Word32 mpysu_shr16(Word16 var1, Word32 var2)

{
  Word32 L_var_out;

  L_var_out = (Word32)(unsigned short)(extract_l(var2)) * (Word32) var1;
  L_var_out = L_var_out >> 15;

  return L_var_out;
}

Word32 L_mult_ls(Word32 var1, Word16 var2)

{
  Word32 L_var_out;

  L_var_out = (Word32)(unsigned short)(extract_l(var1)) * (Word32) var2;
  L_var_out = L_var_out >> 15;
  L_var_out = L_mac(L_var_out, extract_h(var1), var2);

  return L_var_out;
}

Word32 L_mult_sl(Word16 var2, Word32 var1)

{
  Word32 L_var_out;

  L_var_out = (Word32)(unsigned short)(extract_l(var1)) * (Word32) var2;
  L_var_out = L_var_out >> 15;
  L_var_out = L_mac(L_var_out, extract_h(var1), var2);

  return L_var_out;
}
 
Word32 mpysu( Word32 var1, Word32 var2 ) 
{ 
  Word32 L_var_out;

  L_var_out = (Word32)(extract_h(var1)) * 
              (Word32)(unsigned short)(extract_l(var2));
  L_var_out *= 2;

  return L_var_out;
}


void Write_64(Word64 * Fifo, Word64 Value)

{
	* Fifo =  Value;
}

Word64 Read_642(const Word64 * Fifo)

{
	return *Fifo;
}

int bmtset(Word16 Sema, unsigned short mask)

{ 
      /* TO BE DONE */
      return 0;
}


 

void debug() {}
void debugev() {}
void mark() {}
void trap() {}
void wait() {}
void stop() {}
void ei() {}
void di() {}
void illegal() {}

void trap_r(void *Par) {}
int trap_d(int Par) {return 0;}

void trap0_r(void *Par) {}
void trap1_r(void *Par) {}
void trap2_r(void *Par) {}
void trap3_r(void *Par) {}

int trap0_d(int Par) {return 0;}
int trap1_d(int Par) {return 0;}
int trap2_d(int Par) {return 0;}
int trap3_d(int Par) {return 0;}

int readSR(void) {return 0;}
void writeSR(int Val) {}
void *readOSP(void) {return 0;}
void writeOSP(void *Val) {}
void setPPL(int Val) {}
void clearSRbit(int bitmask) {}
void setSRbit(int bitmask) {}

Word32 div_iter (Word32 var1, Word16 var2) { return 0;}

void cw_assert(int a) {}

/*swap of input reversing the n LSB, so that max_val=1<<n*/
int br_swap(int input, int max_val)
{
        int nb_bits;    /*number of bits affected by bit reverse mode*/

        int mask;       /*mask to extract subpart of input affected by bit reverse mode (nb_bits bits=1)*/
        int masked_val; /*subpart of input affected by bit reverse mode (nb_bits bits), initial*/
        int swap;       /*subpart of input affected by bit reverse mode (nb_bits bits), swapped*/
        int tmp;        /*temporary value during swap operation*/

        int output;     /*output value, swapped input*/
        int bit_index;  /*index of bits during computation*/
        int bit_value;  /*value represented by bit n (1<<n)*/

        /*number of bits necessary: precomputed*/
        nb_bits=0;
        while((max_val>>nb_bits)!=1) {
                nb_bits++;
        }
        /*mask set: nb_bits=1, others=0*/
        mask=max_val-1;

        /*subpart of input to be swapped*/
        masked_val=input&mask;

        /*effective swap of this masked part*/
        swap=0;
        for(bit_index=0; bit_index<nb_bits; bit_index++) {
                bit_value=(1<<bit_index);
                tmp=(bit_value&masked_val)/bit_value;
                swap+=(tmp*(1<<(nb_bits-bit_index-1)));
        }

        /*output computed*/
        output=(input-masked_val+swap);
        return(output);
}

/*bit reverse increment of input, reversing the n LSB, so that max_val=1<<n*/
int br_inc(int input, int max_val)
{
        int output;
	int nb_bits;
	int mask;

        /*number of bits necessary: precomputed*/
        nb_bits=0;
        while((max_val>>nb_bits)!=1) {
                nb_bits++;
        }
        /*mask set: nb_bits=1, others=0*/
        mask=max_val-1;

        output=br_swap(input, max_val);
        output++;
        output=br_swap(output, max_val);
	/* Since bit reverse operate on 2^nb_bits we want all the bit outside [2^nb_bits..0] to be unmodified, wrap around in [2^nb_bits..0] */
	output = (input & ~mask) | (output & mask);

        return(output);
}

/*bit reverse increment of input, reversing the n LSB, so that max_val=1<<n, step can be higher than 1  */
/*this function is not to be used in C source file - used for simplification of initial BR IV           */
/*
int br_inc_nu(int input, int max_val, int step)
{
        int output;
	int nb_bits;
	int mask;

        nb_bits=0;
        while((max_val>>nb_bits)!=1) {
                nb_bits++;
        }
        mask=max_val-1;


        output=br_swap(input, max_val);
        output+=step;
        output=br_swap(output, max_val);

	output = (input & ~mask) | (output & mask);

        return(output);
}
*/

Word16 load_fr(Word16 a)
{
	return a;
}
Word16 load_fr_ext_val_none(Word16 a)
{
	return a;
}
Word32 load_lfr_ext_val_val(Word32 a)
{
	return a;
}

void clearEMRbit(int value)
{
	if (value==2)		Overflow = 1;
}

#endif



