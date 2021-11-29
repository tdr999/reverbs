/* *** Copyright Freescale Semiconductor, Inc, 2005 *** */ 
/*_____________________
 |                     |
 | Basic types.        |
 |_____________________|
*/


#ifndef __PROTOTYPE_H
#define __PROTOTYPE_H
# pragma reject_floats off

#ifdef __cplusplus
	extern "C" {
#endif

/*Conditionnal replacement of prototype functions                                       */
/* _ENTERPRISE_C_ is always defined by scc/IDE, and may appear in customers applications*/
/* _CW_NO_PROTO_REPLACE_ can be defined to prevent replacement of prototype functions   */
/*Replacement performed iff first defined, second undefined. Otherwise use definitions  */
/*in prototype.c                                                                        */

#undef _CW_X_PROTO_

#ifdef _ENTERPRISE_C_
#ifndef _CW_NO_PROTO_REPLACE_
#ifndef _CW_X_PROTO_
#define _CW_X_PROTO_
#endif
#endif
#endif


/*shr_r and L_shr_r are not macros but inlined functions instead when defined	*/
/*the macro implementation causes problems with reentrant code MTWX12460	*/

#define _CW_X_NEW_SHR_R_

typedef signed char Word8;
typedef short Word16;
typedef unsigned short UWord16;
typedef long Word32;
typedef unsigned long UWord32;
typedef int Flag;

#ifdef _CW_X_SLLD_
typedef long long int Int64;
#endif


#define WORD16(x) ( (Word16) ( (Word32) ((x + 1.0)*((float) (1<<15))) - (1<<15))) 
#define WORD32(x) ((Word32)-(x*(1<<31) + 0.5))


#ifdef BIG_ENDIAN
typedef struct Word40 {
        UWord32 body;
        char gap[3];    /* Needed because of extension layout in memory */
        char ext;
} Word40;
#else
typedef struct Word40 {
        UWord32 body;
        char ext;
} Word40;
#endif

typedef struct {
    Word32  msb;
    UWord32 lsb;
} Word64;

#ifdef _ENTERPRISE_C_
#pragma align Word64 8
#endif

/* Vector Support Types */

typedef long Vector_Type32;					/*32-bits vector variable*/
typedef char Vector_Component8;				/*8-bits vector component*/
typedef short Vector_Component16;			/*16-bits vector component*/
typedef unsigned char Vector_ComponentU8;	/*8-bits unsigned vector component*/
typedef unsigned short Vector_ComponentU16;	/*16-bits unsigned vector component*/

typedef Word40 Vector_Type40;				/*40-bits vector variable*/
typedef int Vector_Component20;				/*20-bits vector component*/

/* End Vector Support */

/*___________________________________________________________________________
 |                                                                           |
 |   Constants and Globals                                                   |
 |___________________________________________________________________________|
*/

#define MAX_32 (Word32)0x7fffffffL
#define MIN_32 (Word32)0x80000000L
#define MAX_16 (Word16)0x7fff
#define MIN_16 (Word16)0x8000

#ifdef _CW_X_PROTO_
/******************************************************************** 
   Predefined basic intrinsics. 
   Builtin support for these functions is implemented in the 
   compiler's code generator.
   The intrinsic functions are defined in the compiler's
   defined functions name space. They are redefined here
   to the ETSI naming convention.
 ********************************************************************/

/************************************/
/* Fractional arithmetic primitives */
/************************************/

#define add2(v1,v2)        _add2(v1,v2)
#define sub2(v1,v2)        _sub2(v1,v2)
#define max2(v1,v2)        _max2(v1,v2)
#define min2(v1,v2)        _min2(v1,v2)
#define add(v1,v2)         _add(v1,v2)
#define sub(v1,v2)         _sub(v1,v2)
#define abs_s(v)           _abs_s(v)
#define shl(v1,v2)         _shl(v1,v2)
#define shl_nosat(v1,v2)   _shl_nosat(v1,v2)
#define shr(v1,v2)         _shr(v1,v2)
#define shr_nosat(v1,v2)   _shr_nosat(v1,v2)
#define mult(v1,v2)        _mult(v1,v2)
#define mult_nomac(v1,v2)  _mult_nomac(v1,v2)
#define mult_r(v1,v2)      _mult_r(v1,v2)
#define negate(v)          _negate(v)
#define extract_h(v)       _extract_msb(v)
#define extract_l(v)       _extract_lsb(v)
#define Extract(v1,v2)	   _Extract(v1,v2)
#define ExtractU(v1,v2)	   _ExtractU(v1,v2)
#define Extract_reg(v1,v2)      _Extract_reg(v1,v2)
#define ExtractU_reg(v1,v2)	_ExtractU_reg(v1,v2)

#define round2(v)           _round(v)
#define div_s(v1,v2)       _div_s(v1,v2)
#define div_iter(v1,v2)    _div_iter(v1,v2)
#define norm_s(v)          _norm_s(v)
#define neg_norm_s(v)      _neg_norm_s(v)
#define saturate(v)        _sat(v)

#define max(v1,v2)         _max(v1,v2)
#define maxu(v1,v2)		   _maxu(v1,v2)
#define min(v1,v2)         _min(v1,v2)
#define minu(v1,v2)        _minu(v1,v2)
#define maxm(v1,v2)        _maxm(v1,v2)

/*****************************************/
/* Long Fractional arithmetic primitives */
/*****************************************/

#define L_add(v1,v2)           _L_add(v1,v2)
#define L_sub(v1,v2)           _L_sub(v1,v2)
#define L_mult(v1,v2)          _L_mult(v1,v2)
#define L_mult_nomac(v1,v2)    _L_mult_nomac(v1,v2)
#define L_negate(v)            _L_negate(v)
#define L_shl(v1,v2)           _L_shl(v1,v2)
#define L_shl_nosat(v1,v2)     _L_shl_nosat(v1,v2)
#define L_shr(v1,v2)           _L_shr(v1,v2)
#define L_shr_nosat(v1,v2)     _L_shr_nosat(v1,v2)
#define L_deposit_h(v)         _deposit_msb(v)
#define L_deposit_l(v)         _deposit_lsb(v)
#define L_abs(v)               _L_abs(v)
#define norm_l(v)              _norm_l(v)
#define neg_norm_l(v)          _neg_norm_l(v)
#define L_sat(v)               _L_sat(v)
#define L_max(v1,v2)           _L_max(v1,v2)
#define L_maxu(v1,v2)          _L_maxu(v1,v2)
#define L_min(v1,v2)           _L_min(v1,v2)
#define L_minu(v1,v2)          _L_minu(v1,v2)
#define L_maxm(v1,v2)          _L_maxm(v1,v2)

#define load_fr(v)               _load_fr(v)
#define load_fr_ext_val_none(v)  _load_fr_ext_val_none(v)
#define load_lfr_ext_val_val(v)  _load_lfr_ext_val_val(v)

#define clearEMRbit(v)			_clearEMRbit(v)

#define Set_Overflow(v)	       _Set_Overflow(v)
#define	Get_Overflow()	       _Get_Overflow()
#define	Test_Overflow()	       _Test_Overflow()

#define	Clip(v1,v2)            _Clip(v1,v2)

#define setnosat()             _setnosat()
#define setsat32()             _setsat32()
#define set2crm()              _set2crm()
#define setcnvrm()             _setcnvrm()
#define Ovl_Load_Address(v)    _Ovl_Load_Address(v)

#define Write_64(v1,v2)        *(v1) = (v2)
#define Read_64(v)             *(v)
/*#define Write_64(v1,v2)	       _Write_64(v1,v2)*/
/*#define Read_64(v)             _Read_64(v)*/
#define bmtset(v1,v2)          _bmtset(v1,v2)

#define trap_r(v)              _trap_r(v)
#define trap_d(v)              _trap_d(v)
#define trap0_r(v)             _trap0_r(v)
#define trap1_r(v)             _trap1_r(v)
#define trap2_r(v)             _trap2_r(v)
#define trap3_r(v)             _trap3_r(v)
#define trap0_d(v)             _trap0_d(v)
#define trap1_d(v)             _trap1_d(v)
#define trap2_d(v)             _trap2_d(v)
#define trap3_d(v)             _trap3_d(v)

#define readSR(void)           _readSR(void)
#define writeSR(v)             _writeSR(v)
#define readOSP(void)          _readOSP(void)
#define writeOSP(v)            _writeOSP(v)
#define setPPL(v)              _setPPL(v)
#define clearSRbit(v)	       _clearSRbit(v)
#define setSRbit(v)            _setSRbit(v)

#define L_mac(L_var3, var1, var2) (L_add(L_var3,L_mult(var1, var2)))
#define L_msu(L_var3, var1, var2) (L_sub(L_var3,L_mult(var1, var2)))
#define mac_r(L_var3, var1, var2) (round(L_add(L_var3,L_mult(var1, var2))))
#define msu_r(L_var3, var1, var2) (round(L_sub(L_var3,L_mult(var1, var2))))

#ifndef _CW_X_NEW_SHR_R_
static Word16 _CW_shrr_v1,_CW_shrr_v2;
static Word32 _CW_L_shrr_v1;
static Word40 _CW_X_shrr_v1;

#define shr_r(var1,var2)  ( ((_CW_shrr_v1=(var1)),(_CW_shrr_v2=(var2))>0)?\
             add(shr(_CW_shrr_v1,_CW_shrr_v2),((_CW_shrr_v1>>(_CW_shrr_v2-1))&1)):\
             shr(_CW_shrr_v1,_CW_shrr_v2))

#define L_shr_r(L_var1,var2) ( ((_CW_L_shrr_v1=(L_var1)),(_CW_shrr_v2=(var2))>0)?\
             L_add(L_shr(_CW_L_shrr_v1,_CW_shrr_v2),((_CW_L_shrr_v1>>(_CW_shrr_v2-1))&1)):\
             L_shr(_CW_L_shrr_v1,_CW_shrr_v2) )
             
#define X_shr_r(X_var1,var2) ( ((_CW_X_shrr_v1=(X_var1)),(_CW_shrr_v2=(var2))>0)?\
             X_add(X_shr(_CW_X_shrr_v1,_CW_shrr_v2),(X_set(0, X_shr(_CW_X_shrr_v1,(_CW_shrr_v2-1)).body&1))):\
             X_shr(_CW_X_shrr_v1,_CW_shrr_v2) )                       
#endif

/****************************************************/
/* Fractional arithmetic with guard bits primitives */
/****************************************************/

#define X_set(v1,v2)          _X_set(v1,v2)
#define X_extend(v)           _X_extend(v)
#define X_extract_h(v)        _X_extract_h(v)
#define X_extract_l(v)        _X_extract_l(v)
#define X_round(v)            _X_round(v)
#define X_norm(v)             _X_norm(v)
#define X_trunc(v)            _X_trunc(v)
#define X_guard(v)            _X_guard(v)
#define X_add(v1,v2)          _X_add(v1,v2)
#define X_add_sat(v1,v2)          _X_add_sat(v1,v2)
#define X_sub(v1,v2)          _X_sub(v1,v2)
#define X_sub_sat(v1,v2)	  _X_sub_sat(v1,v2)
#define X_mult(v1,v2)         _X_mult(v1,v2)
#define X_shl(v1,v2)          _X_shl(v1,v2)
#define X_shl_sat(v1,v2)          _X_shl_sat(v1,v2)
#define X_shr(v1,v2)          _X_shr(v1,v2)
#define X_lsl(v1,v2)          _X_lsl(v1,v2)
#define X_lsr(v1,v2)          _X_lsr(v1,v2)
#define X_abs(v)              _X_abs(v)
#define X_abs_sat(v)          _X_abs_sat(v)
#define X_sat(v)              _X_sat(v)
#define X_or(v1,v2)           _X_or(v1,v2)
#define X_xor(v1,v2)          _X_xor(v1,v2)
#define X_cmpeq(v1,v2)        _X_cmpeq(v1,v2)
#define X_cmpgt(v1,v2)        _X_cmpgt(v1,v2)
#define X_rol(v)              _X_rol(v)
#define X_ror(v)              _X_ror(v)
#define X_rol_unsafe(v)       _X_rol_unsafe(v)
#define X_ror_unsafe(v)       _X_ror_unsafe(v)

#define X_mac(X_var3,var1,var2) X_add((X_var3),X_mult((var1),(var2)))
#define X_msu(X_var3,var1,var2) X_sub((X_var3),X_mult((var1),(var2)))

/*****************************************************/
/* Double precision fractional arithmetic primitives */
/*****************************************************/

#define D_set(v1,v2)          _D_set(v1,v2)
#define D_add(v1,v2)          _D_add(v1,v2)
#define D_add_opt(v1,v2)      _D_add_opt(v1,v2)
#define D_sub(v1,v2)          _D_sub(v1,v2)
#define D_mult(v1,v2)         _D_mult(v1,v2)
#define D_mult_opt(v1,v2)     _D_mult_opt(v1,v2)
#define D_mult_msp(v1,v2)     _D_mult_msp(v1,v2)
#define D_cmpeq(v1,v2)        _D_cmpeq(v1,v2)
#define D_cmpgt(v1,v2)        _D_cmpgt(v1,v2)
#define D_sat(v)              _D_sat(v)
#define D_round(v)            _D_round(v)

#define D_extract_h(v)        _D_get_msb(v)
#define D_extract_l(v)        _D_get_lsb(v)

#define D_get_msb(v)          _D_get_msb(v)
#define D_get_lsb(v)          _D_get_lsb(v)

#ifdef _CW_X_SLLD_
#define LL_get_msb(v)         _LL_get_msb(v)
#define LL_get_lsb(v)         _LL_get_lsb(v)
#define Db_get_msb(v)         _Db_get_msb(v)
#define Db_get_lsb(v)         _Db_get_lsb(v)
#define	LL_to_Db(v)           _LL_to_Db(v)
#define	Db_to_LL(v)           _Db_to_LL(v)
#endif

#define norm_ll(L_var1)              _norm_ll(L_var1)
#define neg_norm_ll(L_var1)          _neg_norm_ll(L_var1)
#define D_mac(D_var3,L_var1,L_var2) D_add((D_var3),D_mult((L_var1),(L_var2)))
#define D_msu(D_var3,L_var1,L_var2) D_sub((D_var3),D_mult((L_var1),(L_var2)))

/* V5 packed moves */
#define read_b(addr)						_read_b(addr)
#define read_4b(addr, d1, d2, d3, d4)		{d1 = read_b(addr); d2 = read_b(addr); d3 = read_b(addr); d4 = read_b(addr);}
#define read_l(addr)						_read_l(addr)
#define read_2l(addr, dest1, dest2)			{dest1 = read_l(addr); dest2 = read_l(addr);}

#define write_b(addr, src)					_write_b(addr, src)
#define write_4b(addr, s1, s2, s3, s4)		{write_b(addr, s1); write_b(addr, s2); write_b(addr, s3); write_b(addr, s4);}
#define write_l(src1, src2)					_write_l(src1, src2)
#define write_2l(addr, src1, src2)			{write_l(addr, src1); write_l(addr, src2);}

/*****************************************************/
/* V5: Syncio, Syncm Support                         */
/*****************************************************/

/*syncio load*/
#define syncio_read_b(src)			_syncio_read_b(src)
#define syncio_read_ub(src)			_syncio_read_ub(src)
#define syncio_read_w(src)			_syncio_read_w(src)
#define syncio_read_uw(src)			_syncio_read_uw(src)
#define syncio_read_l(src)			_syncio_read_l(src)
#define syncio_read_ul(src)			_syncio_read_ul(src)

/*syncm load*/
#define syncm_read_b(src)			_syncm_read_b(src)
#define syncm_read_ub(src)			_syncm_read_ub(src)
#define syncm_read_w(src)			_syncm_read_w(src)
#define syncm_read_uw(src)			_syncm_read_uw(src)
#define syncm_read_l(src)			_syncm_read_l(src)
#define syncm_read_ul(src)			_syncm_read_ul(src)

/*syncio store*/
#define syncio_write_b(dst, src)	_syncio_write_b(dst, src)
#define syncio_write_ub(dst, src)	_syncio_write_ub(dst, src)
#define syncio_write_w(dst, src)	_syncio_write_w(dst, src)
#define syncio_write_uw(dst, src)	_syncio_write_uw(dst, src)
#define syncio_write_l(dst, src)	_syncio_write_l(dst, src)
#define syncio_write_ul(dst, src)	_syncio_write_ul(dst, src)

/*syncm store*/
#define syncm_write_b(dst, src)		_syncm_write_b(dst, src)
#define syncm_write_ub(dst, src)	_syncm_write_ub(dst, src)
#define syncm_write_w(dst, src)		_syncm_write_w(dst, src)
#define syncm_write_uw(dst, src)	_syncm_write_uw(dst, src)
#define syncm_write_l(dst, src)		_syncm_write_l(dst, src)
#define syncm_write_ul(dst, src)	_syncm_write_ul(dst, src)


/* scaling*/
#define force_moves_l(ptr, src)			_force_moves_l(ptr, src)
#define force_moves_f(ptr, src)			_force_moves_f(ptr, src)

/* unaligned access */
#define setalign(src)					_setalign(src)
#define unaligned_load(src)				_unaligned_load(src)

/*****************************************************/
/* V5: Vector Support                                */
/*****************************************************/

/* load, store, pack, unpack */
#define V_pack_2w(src_var1, src_var2)				_V_pack_2w(src_var1, src_var2)
#define V_pack_2fr(src_var1, src_var2)				_V_pack_2fr(src_var1, src_var2)
#define V_unpack_2w1(src_vect)						_V_unpack_2w1(src_vect)
#define V_unpack_2w(src_vect, dst_var1, dst_var2)	\
	*(dst_var1) = _V_unpack_2w1((src_vect)), *(dst_var2) = _V_unpack_2w1((src_vect))

#define V_read2_2b(src_mem)							_V_read2_2b(src_mem)
#define V_read2_2ub(src_mem)						_V_read2_2ub(src_mem)
#define V_write2_2b(dst_mem, src_vect)				_V_write2_2b(dst_mem, src_vect)

#define V_read2_2b4(src_mem)						_V_read2_2b4(src_mem)
#define V_read2_2ub4(src_mem)						_V_read2_2ub4(src_mem)
#define V_write2_2b4(dst_mem, src_vect)				_V_write2_2b4(dst_mem, src_vect)

#define V_read2_2b8(src_mem)						_V_read2_2b8(src_mem)
#define V_read2_2ub8(src_mem)						_V_read2_2ub8(src_mem)
#define V_write2_2b8(dst_mem, src_vect)				_V_write2_2b8(dst_mem, src_vect)

/*#define V_read2_4b(src_mem, dst_vect1, dst_vect2)	\
	*dst_vect1 = _V_read2_2b4(src_mem), *dst_vect2 = _V_read2_2b4((Vector_Component8*)src_mem+2)*/
#define V_read2_4b(src_mem, dst_vect1, dst_vect2)	\
	*dst_vect1 = _V_read2_2b4(src_mem), *dst_vect2 = _V_read2_2b4(0)

	
/*#define V_read2_4ub(src_mem, dst_vect1, dst_vect2)	\
	*dst_vect1 = _V_read2_2ub4(src_mem), *dst_vect2 = _V_read2_2ub4((Vector_ComponentU8*)src_mem+2)*/
#define V_read2_4ub(src_mem, dst_vect1, dst_vect2)	\
	*dst_vect1 = _V_read2_2ub4(src_mem), *dst_vect2 = _V_read2_2ub4(0)


/*#define V_write2_4b(dst_mem, src_vect1, src_vect2)	\
	_V_write2_2b4(dst_mem, src_vect1), _V_write2_2b4((Vector_Component8*)dst_mem+2, src_vect2)*/
#define V_write2_4b(dst_mem, src_vect1, src_vect2)	\
	_V_write2_2b4(dst_mem, src_vect1), _V_write2_2b4(0, src_vect2)


/*#define V_read2_8b(src_mem, dst_vect1, dst_vect2, dst_vect3, dst_vect4)	\
	*dst_vect1 = _V_read2_2b8(src_mem), *dst_vect2 = _V_read2_2b8((Vector_Component8*)src_mem+2),  *dst_vect3 = _V_read2_2b8((Vector_Component8*)src_mem+4),  *dst_vect4 = _V_read2_2b8((Vector_Component8*)src_mem+6)*/
#define V_read2_8b(src_mem, dst_vect1, dst_vect2, dst_vect3, dst_vect4)	\
	*dst_vect1 = _V_read2_2b8(src_mem), *dst_vect2 = _V_read2_2b8(0),  *dst_vect3 = _V_read2_2b8(0),  *dst_vect4 = _V_read2_2b8(0)


/*#define V_read2_8ub(src_mem, dst_vect1, dst_vect2, dst_vect3, dst_vect4)	\
	*dst_vect1 = _V_read2_2ub8(src_mem), *dst_vect2 = _V_read2_2ub8((Vector_ComponentU8*)src_mem+2),  *dst_vect3 = _V_read2_2ub8((Vector_ComponentU8*)src_mem+4),  *dst_vect4 = _V_read2_2ub8((Vector_ComponentU8*)src_mem+6)*/
#define V_read2_8ub(src_mem, dst_vect1, dst_vect2, dst_vect3, dst_vect4)	\
	*dst_vect1 = _V_read2_2ub8(src_mem), *dst_vect2 = _V_read2_2ub8(0),  *dst_vect3 = _V_read2_2ub8(0),  *dst_vect4 = _V_read2_2ub8(0)


/*#define V_write2_8b(dst_mem, src_vect1, src_vect2, src_vect3, src_vect4)	\
	_V_write2_2b8(dst_mem, src_vect1), _V_write2_2b8((Vector_Component8*)dst_mem+2, src_vect2), _V_write2_2b8((Vector_Component8*)dst_mem+4, src_vect3), _V_write2_2b8((Vector_Component8*)dst_mem+6, src_vect4)*/
#define V_write2_8b(dst_mem, src_vect1, src_vect2, src_vect3, src_vect4)	\
	_V_write2_2b8(dst_mem, src_vect1), _V_write2_2b8(0, src_vect2), _V_write2_2b8(0, src_vect3), _V_write2_2b8(0, src_vect4)

#define V_read_w(src_mem, dst_vect)					_V_read_w(src_mem, dst_vect)
#define V_read_fr(src_mem, dst_vect)				_V_read_fr(src_mem, dst_vect)

/* tfr.w */
#define V_tfrw_ll(dest, src)						_V_tfrw_ll(dest, src)
#define V_tfrw_lh(dest, src)						_V_tfrw_lh(dest, src)
#define V_tfrw_hl(dest, src)						_V_tfrw_hl(dest, src)
#define V_tfrw_hh(dest, src)						_V_tfrw_hh(dest, src)

/* modify - swap, tfr */
#define V_swap(src_vect)							_V_swap(src_vect)
#define V_swapb(src_vect)							_V_swapb(src_vect)
#define V_swapb2(src_vect)							_V_swapb2(src_vect)

/* world level copy */
#define V_pack_ll_hh(src_vect1, src_vect2)			_V_pack_ll_hh(src_vect1, src_vect2)
#define V_pack_lh_hl(src_vect1, src_vect2)			_V_pack_lh_hl(src_vect1, src_vect2)
#define V_pack_hl_lh(src_vect1, src_vect2)			_V_pack_hl_lh(src_vect1, src_vect2)
#define V_pack_hh_ll(src_vect1, src_vect2)			_V_pack_hh_ll(src_vect1, src_vect2)

#define V_add_w_ll(src_vect1, src_vect2)			_V_add_w_ll(src_vect1, src_vect2)
#define V_add_w_lh(src_vect1, src_vect2)			_V_add_w_lh(src_vect1, src_vect2)
#define V_add_w_hl(src_vect1, src_vect2)			_V_add_w_hl(src_vect1, src_vect2)
#define V_add_w_hh(src_vect1, src_vect2)			_V_add_w_hh(src_vect1, src_vect2)

#define V_sub_w_ll(src_vect1, src_vect2)			_V_sub_w_ll(src_vect1, src_vect2)
#define V_sub_w_lh(src_vect1, src_vect2)			_V_sub_w_lh(src_vect1, src_vect2)
#define V_sub_w_hl(src_vect1, src_vect2)			_V_sub_w_hl(src_vect1, src_vect2)
#define V_sub_w_hh(src_vect1, src_vect2)			_V_sub_w_hh(src_vect1, src_vect2)


#define V_sod2aaii(src_vect1, src_vect2)			_V_sod2aaii(src_vect1, src_vect2)
#define V_sod2aaxx(src_vect1, src_vect2)			_V_sod2aaxx(src_vect1, src_vect2)
#define V_sod2asii(src_vect1, src_vect2)			_V_sod2asii(src_vect1, src_vect2)
#define V_sod2asxx(src_vect1, src_vect2)			_V_sod2asxx(src_vect1, src_vect2)
#define V_sod2saii(src_vect1, src_vect2)			_V_sod2saii(src_vect1, src_vect2)
#define V_sod2saxx(src_vect1, src_vect2)			_V_sod2saxx(src_vect1, src_vect2)
#define V_sod2ssii(src_vect1, src_vect2)			_V_sod2ssii(src_vect1, src_vect2)
#define V_sod2ssxx(src_vect1, src_vect2)			_V_sod2ssxx(src_vect1, src_vect2)

#define V_add2(src_vect1, src_vect2)				_add2(src_vect1, src_vect2)
#define V_sub2(src_vect1, src_vect2)				_sub2(src_vect1, src_vect2)
#define V_abs2(src_vect1)							_V_abs2(src_vect1)
#define V_neg2(src_vect1)							_V_neg2(src_vect1)
#define V_min2(src_vect1, src_vect2)				_min2(src_vect1, src_vect2)
#define V_max2(src_vect1, src_vect2)				_max2(src_vect1, src_vect2)


#define V_asl2(src_vect)							_V_asl2(src_vect)
#define V_asll2(src_vect, val)						_V_asll2(src_vect, val)
#define V_asr2(src_vect)							_V_asr2(src_vect)
#define V_asrr2(src_vect, val)						_V_asrr2(src_vect, val)
#define V_lsll2(src_vect, val)						_V_lsll2(src_vect, val)
#define V_lsr2(src_vect)							_V_lsr2(src_vect)
#define V_lsrr2(src_vect, val)						_V_lsrr2(src_vect, val)

#define V_satu2b(src_vect)							_V_satu2b(src_vect)
#define V_avgu4(src_vect1, src_vect2)				_V_avgu4(src_vect1, src_vect2)

#define V_impysu2(src_vect1, src_vect2)				_V_impysu2(src_vect1, src_vect2)
#define V_add2_20Component(src_vect1, src_vect2)	_V_add2_20Component(src_vect1, src_vect2)
#define V_imacsu2_mpy(src_vect1, src_vect2)			_V_imacsu2_mpy(src_vect1, src_vect2)
#define V_imacsu2(src_vect1, src_vect2, src_vect3)  _V_add2_20Component((src_vect3), _V_imacsu2_mpy((src_vect1), (src_vect2)))

/*#define V_sr4t(src_vect1, src_vect2)				_V_sr4t(src_vect1, src_vect2)*/
#define V_clip2(src_vect, imm)						_V_clip2(src_vect, imm)

#define V_dummy_read_32(src_vect)					_V_dummy_read_32(src_vect)
#define V_dummy_read_2x32(src1, src2)				_V_dummy_read_2x32(src1, src2)

#define V_sad41(src_vect1, src_vect2)				_V_sad41(src_vect1, src_vect2)
#define V_sad4(src1, src2, dest)					V_sad41(V_dummy_read_2x32(src1, src2), dest)

/*mac instructions*/
#define V_L_mac_hh(L_var3, var1, var2)				(L_add((L_var3),V_L_mult_hh_add((var1), (var2))))
#define V_L_msu_hh(L_var3, var1, var2)				(L_sub((L_var3),V_L_mult_hh_sub((var1), (var2))))

#define V_X_mac_hh(X_var3, var1, var2)				(X_add((X_var3),V_X_mult_hh_add((var1), (var2))))
#define V_X_msu_hh(X_var3, var1, var2)				(X_sub((X_var3),V_X_mult_hh_sub((var1), (var2))))

#define V_L_mac_hl(L_var3, var1, var2)				(L_add((L_var3),V_L_mult_hl_add((var1), (var2))))
#define V_L_msu_hl(L_var3, var1, var2)				(L_sub((L_var3),V_L_mult_hl_sub((var1), (var2))))

#define V_X_mac_hl(X_var3, var1, var2)				(X_add((X_var3),V_X_mult_hl_add((var1), (var2))))
#define V_X_msu_hl(X_var3, var1, var2)				(X_sub((X_var3),V_X_mult_hl_sub((var1), (var2))))

#define V_L_mac_lh(L_var3, var1, var2)				(L_add((L_var3),V_L_mult_lh_add((var1), (var2))))
#define V_L_msu_lh(L_var3, var1, var2)				(L_sub((L_var3),V_L_mult_lh_sub((var1), (var2))))

#define V_X_mac_lh(X_var3, var1, var2)				(X_add((X_var3),V_X_mult_lh_add((var1), (var2))))
#define V_X_msu_lh(X_var3, var1, var2)				(X_sub((X_var3),V_X_mult_lh_sub((var1), (var2))))

#define V_L_mac_ll(L_var3, var1, var2)				(L_add((L_var3),V_L_mult_ll_add((var1), (var2))))
#define V_L_msu_ll(L_var3, var1, var2)				(L_sub((L_var3),V_L_mult_ll_sub((var1), (var2))))

#define V_X_mac_ll(X_var3, var1, var2)				(X_add((X_var3),V_X_mult_ll_add((var1), (var2))))
#define V_X_msu_ll(X_var3, var1, var2)				(X_sub((X_var3),V_X_mult_ll_sub((var1), (var2))))


/*macr instructions*/
#define V_mac_r_hh(L_var3, var1, var2)				(round(L_add((L_var3),V_L_mult_hh_round((var1), (var2)))))
#define V_msu_r_hh(L_var3, var1, var2)				(round(L_sub((L_var3),V_L_mult_hh_sub_round((var1), (var2)))))

#define V_mac_r_hl(L_var3, var1, var2)				(round(L_add((L_var3),V_L_mult_hl_round((var1), (var2)))))
#define V_msu_r_hl(L_var3, var1, var2)				(round(L_sub((L_var3),V_L_mult_hl_sub_round((var1), (var2)))))

#define V_mac_r_lh(L_var3, var1, var2)				(round(L_add((L_var3),V_L_mult_lh_round((var1), (var2)))))
#define V_msu_r_lh(L_var3, var1, var2)				(round(L_sub((L_var3),V_L_mult_lh_sub_round((var1), (var2)))))

#define V_mac_r_ll(L_var3, var1, var2)				(round(L_add((L_var3),V_L_mult_ll_round((var1), (var2)))))
#define V_msu_r_ll(L_var3, var1, var2)				(round(L_sub((L_var3),V_L_mult_ll_sub_round((var1), (var2)))))


/*mpy instructions*/
#define V_mult_hh(var1, var2)						_V_mult_hh(var1, var2)
#define V_L_mult_hh(var1, var2)						_V_L_mult_hh(var1, var2)
#define V_L_mult_hh_sub(var1, var2)					_V_L_mult_hh_sub(var1, var2)
#define V_L_mult_hh_add(var1, var2)					_V_L_mult_hh_add(var1, var2)
#define V_L_mult_hh_round(var1, var2)				_V_L_mult_hh_round(var1, var2)
#define V_L_mult_hh_sub_round(var1, var2)			_V_L_mult_hh_sub_round(var1, var2)
#define V_X_mult_hh(var1, var2)						_V_X_mult_hh(var1, var2)
#define V_X_mult_hh_add(var1, var2)					_V_X_mult_hh_add(var1, var2)
#define V_X_mult_hh_sub(var1, var2)					_V_X_mult_hh_sub(var1, var2)

#define V_mult_lh(var1, var2)						_V_mult_lh(var1, var2)
#define V_L_mult_lh(var1, var2)						_V_L_mult_lh(var1, var2)
#define V_L_mult_lh_sub(var1, var2)					_V_L_mult_lh_sub(var1, var2)
#define V_L_mult_lh_add(var1, var2)					_V_L_mult_lh_add(var1, var2)
#define V_L_mult_lh_round(var1, var2)				_V_L_mult_lh_round(var1, var2)
#define V_L_mult_lh_sub_round(var1, var2)			_V_L_mult_lh_sub_round(var1, var2)
#define V_X_mult_lh(var1, var2)						_V_X_mult_lh(var1, var2)
#define V_X_mult_lh_add(var1, var2)					_V_X_mult_lh_add(var1, var2)
#define V_X_mult_lh_sub(var1, var2)					_V_X_mult_lh_sub(var1, var2)

#define V_mult_hl(var1, var2)						_V_mult_hl(var1, var2)
#define V_L_mult_hl(var1, var2)						_V_L_mult_hl(var1, var2)
#define V_L_mult_hl_sub(var1, var2)					_V_L_mult_hl_sub(var1, var2)
#define V_L_mult_hl_add(var1, var2)					_V_L_mult_hl_add(var1, var2)
#define V_L_mult_hl_round(var1, var2)				_V_L_mult_hl_round(var1, var2)
#define V_L_mult_hl_sub_round(var1, var2)			_V_L_mult_hl_sub_round(var1, var2)
#define V_X_mult_hl(var1, var2)						_V_X_mult_hl(var1, var2)
#define V_X_mult_hl_add(var1, var2)					_V_X_mult_hl_add(var1, var2)
#define V_X_mult_hl_sub(var1, var2)					_V_X_mult_hl_sub(var1, var2)

#define V_mult_ll(var1, var2)						_V_mult_ll(var1, var2)
#define V_L_mult_ll(var1, var2)						_V_L_mult_ll(var1, var2)
#define V_L_mult_ll_sub(var1, var2)					_V_L_mult_ll_sub(var1, var2)
#define V_L_mult_ll_add(var1, var2)					_V_L_mult_ll_add(var1, var2)
#define V_L_mult_ll_round(var1, var2)				_V_L_mult_ll_round(var1, var2)
#define V_L_mult_ll_sub_round(var1, var2)			_V_L_mult_ll_sub_round(var1, var2)
#define V_X_mult_ll(var1, var2)						_V_X_mult_ll(var1, var2)
#define V_X_mult_ll_add(var1, var2)					_V_X_mult_ll_add(var1, var2)
#define V_X_mult_ll_sub(var1, var2)					_V_X_mult_ll_sub(var1, var2)

/*mpyr instructions*/
#define V_mult_r_hh(var1, var2)						_V_mult_r_hh(var1, var2)
#define V_mult_r_lh(var1, var2)						_V_mult_r_lh(var1, var2)
#define V_mult_r_hl(var1, var2)						_V_mult_r_hl(var1, var2)
#define V_mult_r_ll(var1, var2)						_V_mult_r_ll(var1, var2)


/* End Vector Support */

/*****************************************************/
/* Other primitives                                  */
/*****************************************************/

#define L_rol(val) ((val&0x80000000)?((val<<1)|1):(val<<1))
#define L_ror(val) ((long int) ((val&1)?(((unsigned long) val>>1)|0x80000000):((unsigned long)val>>1)))

#define mpyuu(v1,v2)		  _mpyuu(v1,v2)
#define mpyus(v1,v2)          _mpyus(v1,v2)
#define mpysu(v1,v2)          _mpysu(v1,v2)
#define mpyus_shr16(v1,v2)    _mpyus_shr16(v1,v2)
#define mpysu_shr16(v1,v2)    _mpysu_shr16(v1,v2)
#define L_mult_ls(v1,v2)      _L_mult_ls(v1,v2)
#define L_mult_sl(v1,v2)      _L_mult_sl(v1,v2)

#define debug()               asm(" debug")
#define debugev()             asm(" debugev")
#define mark()                asm(" mark")
#define trap()                asm(" trap")
#if defined(_SC3400_) || defined(_SC3200_)
#define wait()                asm(" wait"); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ) 
#define stop()                asm(" stop"); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ); \
                              asm(" nop nop nop nop nop nop nop nop " ) 
#else
#define wait()                asm(" wait")
#define stop()                asm(" stop")
#endif
#define ei()                  _ei()
#define di()                  _di()
#define illegal()             asm(" illegal")

#define cw_assert(v)	      _cw_assert(v)

/* #define br_swap		_br_swap */
#define br_inc(x, n)	_br_inc(x, (n>>1))
/* #define br_inc_nu   	_br_inc_nu */

/* this is the else of the #ifdef _CW_X_PROTO_, i.e. case where prototypes should not be replaced */
#else

extern Flag Overflow;
extern Flag Carry;


/* V5 support */

Word40 V_imacsu2( Vector_Type32 src_vect1,  Vector_Type32 src_vect2,  Word40 src_vect3);
Vector_Type32 V_sad4( Vector_Type32 src_vect1,  Vector_Type32 src_vect2,  Vector_Type32 src_vect3);

/*mac instructions*/
Vector_Type32 V_L_mac_hh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mac_hh( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Type32 V_L_msu_hh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_msu_hh( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Type32 V_L_mac_hl( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mac_hl( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Type32 V_L_msu_hl( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_msu_hl( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Type32 V_L_mac_lh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mac_lh( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Type32 V_L_msu_lh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_msu_lh( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Type32 V_L_mac_ll( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mac_ll( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Type32 V_L_msu_ll( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_msu_ll( Vector_Type40 X_var3,  Vector_Type32 var1,  Vector_Type32 var2);

/*macr instructions*/
Vector_Component16 V_mac_r_hh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Component16 V_msu_r_hh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Component16 V_mac_r_hl( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Component16 V_msu_r_hl( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Component16 V_mac_r_lh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Component16 V_msu_r_lh( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);

Vector_Component16 V_mac_r_ll( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);
Vector_Component16 V_msu_r_ll( Vector_Type32 L_var3,  Vector_Type32 var1,  Vector_Type32 var2);

/* end V5 support */

Word32 L_mac ( Word32 L_var3,  Word16 var1,  Word16 var2);
Word32 L_msu ( Word32 L_var3,  Word16 var1,  Word16 var2);
Word16 mac_r ( Word32 L_var3,  Word16 var1,  Word16 var2);
Word16 msu_r ( Word32 L_var3,  Word16 var1,  Word16 var2);

Word16 shr_r ( Word16 var1,  Word16 var2);
Word32 L_shr_r ( Word32 L_var1,  Word16 var2);
Word40 X_shr_r ( Word40 L_var1,  Word16 var2);

Word16 saturate ( Word32 L_var1);
Word32 L_sat ( Word32 L_var1);

Word40 X_mac( Word40 X_var3,  Word16 var1,  Word16 var2);
Word40 X_msu( Word40 X_var3,  Word16 var1,  Word16 var2);
Word64 D_mac( Word64 D_var3,  Word32 L_var1,  Word32 L_var2);
Word64 D_msu( Word64 D_var3,  Word32 L_var1,  Word32 L_var2);

void Write_64(Word64*  Fifo,  Word64 Value);
Word64 Read_64(Word64*  Fifo);
Word32 L_ror ( Word32 L_var1);
Word32 L_rol ( Word32 L_var1);

#define D_extract_h(DVal)    D_get_msb(DVal)
#define D_extract_l(DVal)    D_get_lsb(DVal)

void debug();
void debugev();
void mark();
void trap();
void wait();
void illegal();
void stop();

/* this is the end of the #ifdef _CW_X_PROTO_ */
#endif

/************************************/
/* Fractional arithmetic primitives */
/************************************/
Word32 add2 ( Word32 var1,  Word32 var2);
Word32 sub2 ( Word32 var1,  Word32 var2);
Word32 max2 ( Word32 var1,  Word32 var2);
Word32 min2 ( Word32 var1,  Word32 var2);

Word16 add ( Word16 var1,  Word16 var2);
Word16 sub ( Word16 var1,  Word16 var2);
Word16 abs_s ( Word16 var1);
Word16 shl ( Word16 var1,  Word16 var2);
Word16 shl_nosat ( Word16 var1,  Word16 var2);
Word16 shr ( Word16 var1,  Word16 var2);
Word16 shr_nosat ( Word16 var1,  Word16 var2);
Word16 mult ( Word16 var1,  Word16 var2);
Word16 mult_nomac ( Word16 var1,  Word16 var2);
Word16 mult_r ( Word16 var1,  Word16 var2);
Word16 negate ( Word16 var1);
Word16 extract_h ( Word32 L_var1);
Word16 extract_l ( Word32 L_var1);
Word16 round2 ( Word32 L_var1);
Word16 div_s ( Word16 var1,  Word16 var2);
Word32 div_iter ( Word32 var1,  Word16 var2);
Word16 norm_s ( Word16 var1);
Word16 neg_norm_s ( Word16 var1);
Word16 saturate ( Word32 L_var1);

Word16 max( Word16 var1,  Word16 var2);
UWord16 maxu( UWord16 var1,  UWord16 var2);
Word16 min( Word16 var1,  Word16 var2);
UWord16 minu( UWord16 var1,  UWord16 var2);
Word16 maxm( Word16 var1,  Word16 var2);

/*****************************************/
/* Long fractional arithmetic primitives */
/*****************************************/
Word32 L_add ( Word32 L_var1,  Word32 L_var2);
Word32 L_sub ( Word32 L_var1,  Word32 L_var2);
Word32 L_mult ( Word16 var1,  Word16 var2);
Word32 L_mult_nomac ( Word16 var1,  Word16 var2);
Word32 L_negate ( Word32 L_var1);
Word32 L_shl ( Word32 L_var1,  Word16 var2);
Word32 L_shl_nosat ( Word32 L_var1,  Word16 var2);
Word32 L_shr ( Word32 L_var1,  Word16 var2);
Word32 L_shr_nosat ( Word32 L_var1,  Word16 var2);
Word32 L_deposit_h ( Word16 var1);
Word32 L_deposit_l ( Word16 var1);
Word32 L_abs ( Word32 L_var1);
Word16 norm_l ( Word32 L_var1);
Word16 neg_norm_l ( Word32 L_var1);
Word32 L_sat ( Word32 L_var1);

Word32 L_max( Word32 L_var1,  Word32 L_var2);
UWord32 L_maxu( UWord32 L_var1,  UWord32 L_var2);
Word32 L_min( Word32 L_var1,  Word32 L_var2);
UWord32 L_minu( UWord32 L_var1,  UWord32 L_var2);
Word32 L_maxm( Word32 L_var1,  Word32 L_var2);

Word16 load_fr( Word16 a);
Word16 load_fr_ext_val_none( Word16 a);
Word32 load_lfr_ext_val_val( Word32 a);

void clearEMRbit( int value);
#define clearNMID()				clearEMRbit(3)
#define clearDOVF()				clearEMRbit(2) 
#define clearILST()				clearEMRbit(1) 
#define clearILIN()				clearEMRbit(0)

void setnosat ();
void setsat32 ();
void set2crm ();
void setcnvrm ();
void * Ovl_Load_Address(void*  Symb_Addr);
/*void Write_64(Word64 * Fifo, Word64 Value);*/
/*Word64 Read_64( Word64 * Fifo);*/
int bmtset( Word16 Sema,  unsigned short mask);

void Set_Overflow( Word32 Value);
int Get_Overflow();
int Test_Overflow();

/* Getting the Core ID at run-time */
int _GetCoreId();

Word32 Clip( Word32 Value,  Word32 mask);

Word32 Extract( Word32 Val,  UWord32 Mask);
UWord32 ExtractU( UWord32 Val,  UWord32 Mask);

Word32 Extract_reg( Word32 Val,  UWord32 Mask);
UWord32 ExtractU_reg( UWord32 Val,  UWord32 Mask);

/*****************************************************/
/* Double precision fractional arithmetic primitives */
/*****************************************************/
Word64 D_set( Word32 left ,  UWord32 right);
Word64 D_add( Word64 left ,  Word64 right);
Word64 D_add_opt( Word64 left ,  Word64 right);
Word64 D_sub( Word64 left ,  Word64 right);
Word64 D_mult( Word32 left ,  Word32 right);
Word64 D_mult_opt( Word32 left ,  Word32 right);
Word32 D_mult_msp( Word32 left ,  Word32 right);
Word64 D_sat( Word64 left);
Word32 D_round( Word64 left);
Word32 D_get_msb( Word64 Val);
Word32 D_get_lsb( Word64 Val);

#ifdef _CW_X_SLLD_
Word32 LL_get_msb( Int64 Val);
UWord32 LL_get_lsb( Int64 Val);

Word32 Db_get_msb( double Val);
UWord32 Db_get_lsb( double Val);

Int64 Db_to_LL( double Val);
double LL_to_Db( Int64 Val);
#endif
Word16 norm_ll( Word64 L_var1);
Word16 neg_norm_ll( Word64 L_var1);

int D_cmpeq( Word64 left,  Word64 right);
int D_cmpgt( Word64 left,  Word64 right);

/****************************************************/
/* Fractional arithmetic with guard bits primitives */
/****************************************************/
Word40 X_set( Word32 guard,  UWord32 body);
Word40 X_extend ( Word32 var1);
Word16 X_extract_h ( Word40 var1);
Word16 X_extract_l ( Word40 var1);
Word16 X_round ( Word40 var1);
Word16 X_norm ( Word40 var1);
Word32 X_trunc ( Word40 var1);
Word32 X_guard ( Word40 var1);
Word40 X_add ( Word40 var1,  Word40 var2);
Word40 X_add_sat ( Word40 var1,  Word40 var2);
Word40 X_sub ( Word40 var1,  Word40 var2);
Word40 X_sub_sat (Word40 var1, Word40 var2);
Word40 X_mult ( Word16 var1,  Word16 var2);
Word40 X_shl ( Word40 var1,  Word16 var2);
Word40 X_shl_sat ( Word40 var1,  Word16 var2);
Word40 X_shr ( Word40 var1,  Word16 var2);
Word40 X_lsl ( Word40 var1,  Word16 var2);
Word40 X_lsr ( Word40 var1,  Word16 var2);
Word40 X_abs ( Word40 var1);
Word40 X_abs_sat ( Word40 var1);
Word32 X_sat ( Word40 var1);
Word40 X_or ( Word40 var1,  Word40 var2);
Word40 X_xor ( Word40 var1,  Word40 var2);
int    X_cmpeq( Word40 var1,  Word40 var2);
int    X_cmpgt( Word40 var1,  Word40 var2);

Word40 X_ror ( Word40 var1);
Word40 X_ror_unsafe ( Word40 var1);
Word40 X_rol ( Word40 var1);
Word40 X_rol_unsafe ( Word40 var1);

void* __clear(void*  src,  unsigned int size);

/*****************************************************/
/* V5: Fetch				                         */
/*****************************************************/

void _dfetch(void*  mem_line);
void _pfetch(void*  mem_line);
void _pfetch_imm(void*  imm_address);

/*****************************************************/
/* V5: Syncio, Syncm Support                         */
/*****************************************************/

void _syncio();
void _syncm();
void _syncio_barrier();

/* V5 packed moves */

Word8 read_b(Word8*  addr);
Word32 read_l(Word32*  addr);

void write_b(Word8*  addr,  Word8 src);
void write_l(Word32*  addr,  Word32 src);

/*syncio load*/
          char syncio_read_b  (volatile char*  src);
 unsigned char syncio_read_ub (volatile unsigned char*  src);
         short syncio_read_w  (volatile short*  src);
unsigned short syncio_read_uw (volatile unsigned short*  src);
           int syncio_read_l  (volatile int*  src);
  unsigned int syncio_read_ul (volatile unsigned int*  src);

/*syncm load*/
          char syncm_read_b   (volatile char*  src);
 unsigned char syncm_read_ub  (volatile unsigned char*  src);
         short syncm_read_w   (volatile short*  src);
unsigned short syncm_read_uw  (volatile unsigned short*  src);
           int syncm_read_l   (volatile int*  src);
  unsigned int syncm_read_ul  (volatile unsigned int*  src);

/*syncio store*/
void syncio_write_b (volatile char*  dst,            char src);
void syncio_write_ub(volatile unsigned char*  dst,   unsigned char src);
void syncio_write_w (volatile short*  dst,           short src);
void syncio_write_uw(volatile unsigned short*  dst,  unsigned short src);
void syncio_write_l (volatile int*  dst,             int src);
void syncio_write_ul(volatile unsigned int*  dst,    unsigned int src);

/*syncm store*/
void syncm_write_b (volatile char*  dst,            char src);
void syncm_write_ub(volatile unsigned char*  dst,   unsigned char src);
void syncm_write_w (volatile short*  dst,           short src);
void syncm_write_uw(volatile unsigned short*  dst,  unsigned short src);
void syncm_write_l (volatile int*  dst,             int src);
void syncm_write_ul(volatile unsigned int*  dst,    unsigned int src);

/* scaling*/
void force_moves_f(Word16*  ptr,  Word16 src);
void force_moves_l(long*  ptr,  long src);

/* unaligned access */
long *setalign(long*  src);
long unaligned_load(long*  src);

/*****************************************************/
/* V5: Vector Support                                */
/*****************************************************/

/* load, store, pack, unpack */
Vector_Type32 V_pack_2w( Vector_Type32 src_var1,  Vector_Type32 src_var2);
Vector_Type32 V_pack_2fr( Vector_Type32 src_var1,  Vector_Type32 src_var2);
#ifndef _CW_X_PROTO_
void V_unpack_2w( Vector_Type32 src_vect, Vector_Component16*  dst_var1, Vector_Component16*  dst_var2);
#endif
Vector_Component16  V_unpack_2w1( Vector_Type32 src_vect);

Vector_Type32 V_read2_2b(Vector_Component8*  src_mem);
Vector_Type32 V_read2_2ub(Vector_ComponentU8*  src_mem);
void V_write2_2b(Vector_Component8*  dst_mem, Vector_Type32 src_vect);

#ifndef _CW_X_PROTO_
void V_read2_4b(Vector_Component8*  src_mem, 
				Vector_Type32*  dst_vect1, Vector_Type32*  dst_vect2);
#endif				
Vector_Type32 V_read2_2b4(Vector_Component8*  src_mem);
#ifndef _CW_X_PROTO_
void V_read2_4ub(Vector_ComponentU8*  src_mem, 
				Vector_Type32*  dst_vect1, Vector_Type32*  dst_vect2);
#endif				
Vector_Type32 V_read2_2ub4(Vector_ComponentU8*  src_mem);
#ifndef _CW_X_PROTO_
void V_write2_4b(Vector_Component8*  dst_mem, 
				 Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
#endif				
void V_write2_2b4(Vector_Component8*  dst_mem,  Vector_Type32 src_vect);
#ifndef _CW_X_PROTO_
void V_read2_8b(Vector_Component8*  src_mem, 
				Vector_Type32*  dst_vect1, Vector_Type32*  dst_vect2, 
				Vector_Type32*  dst_vect3, Vector_Type32*  dst_vect4);
#endif				
Vector_Type32 V_read2_2b8(Vector_Component8*  src_mem);
#ifndef _CW_X_PROTO_
void V_read2_8ub(Vector_ComponentU8*  src_mem, 
				Vector_Type32*  dst_vect1, Vector_Type32*  dst_vect2, 
				Vector_Type32*  dst_vect3, Vector_Type32*  dst_vect4);
#endif				
Vector_Type32 V_read2_2ub8(Vector_ComponentU8 *src_mem);
#ifndef _CW_X_PROTO_
void V_write2_8b(Vector_Component8*  dst_mem, 
				 Vector_Type32 src_vect1,  Vector_Type32 src_vect2, 
				 Vector_Type32 src_vect3,  Vector_Type32 src_vect4);
#endif				
void V_write2_2b8(Vector_Component8*  dst_mem,  Vector_Type32 src_vect);

Vector_Type32 V_read_w(Vector_Component16*  src_mem,  Vector_Type32 src_vect);
Vector_Type32 V_read_fr(Vector_Component16*  src_mem,  Vector_Type32 src_vect);

/* tfr.w */
Vector_Type32 V_tfrw_ll( Vector_Type32 dest,  Vector_Type32 src);
Vector_Type32 V_tfrw_lh( Vector_Type32 dest,  Vector_Type32 src);
Vector_Type32 V_tfrw_hl( Vector_Type32 dest,  Vector_Type32 src);
Vector_Type32 V_tfrw_hh( Vector_Type32 dest,  Vector_Type32 src);

/* modify - swap, tfr */
Vector_Type32 V_swap( Vector_Type32 a);
Vector_Type32 V_swapb( Vector_Type32 src_vect);
Vector_Type32 V_swapb2( Vector_Type32 src_vect);

/* world level copy */
Vector_Type32 V_pack_ll_hh( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_pack_lh_hl( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_pack_hl_lh( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_pack_hh_ll( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);

Vector_Type32 V_add_w_ll( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_add_w_lh( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_add_w_hl( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_add_w_hh( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);

Vector_Type32 V_sub_w_ll( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sub_w_lh( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sub_w_hl( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sub_w_hh( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);


Vector_Type32 V_sod2aaii( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sod2aaxx( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sod2asii( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sod2asxx( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sod2saii( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sod2saxx( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sod2ssii( Vector_Type32 src_vect2,  Vector_Type32 src_vect1);
Vector_Type32 V_sod2ssxx( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
#ifndef _CW_X_PROTO_
Vector_Type32 V_add2( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sub2( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
#endif
Vector_Type32 V_abs2( Vector_Type32 src_vect1);
Vector_Type32 V_neg2( Vector_Type32 src_vect1);
#ifndef _CW_X_PROTO_
Vector_Type32 V_min2( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_max2( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
#endif

Vector_Type32 V_asl2( Vector_Type32 src_vect);
Vector_Type32 V_asll2( Vector_Type32 src_vect,  int val);
Vector_Type32 V_asr2( Vector_Type32 src_vect);
Vector_Type32 V_asrr2( Vector_Type32 src_vect,  int val);
Vector_Type32 V_lsll2( Vector_Type32 src_vect,  int val);
Vector_Type32 V_lsr2( Vector_Type32 src_vect);
Vector_Type32 V_lsrr2( Vector_Type32 src_vect,  int val);

Vector_Type32 V_satu2b( Vector_Type32 src_vect);
Vector_Type32 V_avgu4( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);

Vector_Component20 init_20Component( int value);
Vector_Component20 get_Low20Component( Word40 src_vect);
Vector_Component20 get_High20Component( Word40 src_vect);
Word40 put_Low20Component( Word40 src_vect,  Vector_Component20 comp);
Word40 put_High20Component( Word40 src_vect,  Vector_Component20 comp);
Word40 V_add2_20Component( Word40 src_vect1, Word40 src_vect2);

Word40 V_impysu2( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
/*Vector_Type32 V_sr4t( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);*/
Word40 V_clip2( Word40 src_vect, int imm);

void V_dummy_read_32( Vector_Type32 src_vect);
Vector_Type32 V_dummy_read_2x32( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Vector_Type32 V_sad41( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);
Word40 V_imacsu2_mpy( Vector_Type32 src_vect1,  Vector_Type32 src_vect2);

/*mpy instructions*/
Vector_Component16 V_mult_hh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hh_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hh_sub( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hh_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hh_sub_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_hh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_hh_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_hh_sub( Vector_Type32 var1,  Vector_Type32 var2);

Vector_Component16 V_mult_lh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_lh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_lh_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_lh_sub( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_lh_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_lh_sub_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_lh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_lh_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_lh_sub( Vector_Type32 var1,  Vector_Type32 var2);

Vector_Component16 V_mult_hl( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hl( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hl_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hl_sub( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hl_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_hl_sub_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_hl( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_hl_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_hl_sub( Vector_Type32 var1,  Vector_Type32 var2);

Vector_Component16 V_mult_ll( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_ll( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_ll_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_ll_sub( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_ll_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type32 V_L_mult_ll_sub_round( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_ll( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_ll_add( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Type40 V_X_mult_ll_sub( Vector_Type32 var1,  Vector_Type32 var2);

/*mpyr instructions*/
Vector_Component16 V_mult_r_hh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Component16 V_mult_r_lh( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Component16 V_mult_r_hl( Vector_Type32 var1,  Vector_Type32 var2);
Vector_Component16 V_mult_r_ll( Vector_Type32 var1,  Vector_Type32 var2);
/*
Vector_Type32 V_acs2h_pp_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_pp_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_pp_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_pp_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_pm_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_pm_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_pm_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_pm_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mp_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mp_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mp_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mp_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mm_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mm_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mm_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2h_mm_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pp_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pp_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pp_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pp_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pm_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pm_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pm_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_pm_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mp_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mp_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mp_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mp_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mm_lh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mm_hl(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mm_ll(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
Vector_Type32 V_acs2l_mm_hh(Vector_Type32 src_vect1, Vector_Type32 src_vect2, Vector_Type32 src_vect3);
*/

/* End Vector Support */

/*****************************************************/
/* Other primitives                                  */
/*****************************************************/

Word32 mpyuu( Word32 var1,  Word32 var2);
Word32 mpyus( Word32 var1,  Word32 var2);
Word32 mpysu( Word32 var1,  Word32 var2);
Word32 mpyus_shr16( Word32 var1,  Word16 var2);
Word32 mpysu_shr16( Word16 var1,  Word32 var2);
Word32 L_mult_ls( Word32 var1,  Word16 var2);
Word32 L_mult_sl( Word16 var2,  Word32 var1);

int readSR(void);
void writeSR( int);
void *readOSP(void);
void writeOSP(void* );
void setPPL( int);
void clearSRbit( int);
void setSRbit( int);
void ei();
void di();

void trap_r(void* );
int trap_d( int);
void trap0_r(void* );
void trap1_r(void* );
void trap2_r(void* );
void trap3_r(void* );

int trap0_d( int);
int trap1_d( int);
int trap2_d( int);
int trap3_d( int);

void cw_assert( int);

/* int  br_swap(int index, int max_val); */
/* int  br_inc(int index, int max_val); */
/* int  br_inc_nu(int index, int max_val, int step); */

#ifdef _ENTERPRISE_C_
#ifndef _CW_NO_PROTO_REPLACE_
#ifdef _CW_X_NEW_SHR_R_
inline Word16 shr_r( Word16 var1, Word16 var2){
/*  return           (((var2)>0)? add(shr((var1),(var2)),( Word16)(((var1)>>( Word16)((var2)-1))&1)):shr((var1),(var2))) ; */
  return (Word16)( (((var2)>0)? add(shr((var1),(var2)),(Word16)(((var1)>>(Word16)((var2)-1))&1)):shr((var1),(var2))) );
}

inline Word32 L_shr_r( Word32 L_var1,  Word16 var2) {
  return (((var2)>0)? L_add(L_shr((L_var1),(var2)),(((L_var1)>>(Word16)((var2)-1))&1)):L_shr((L_var1),(var2))) ;
}

inline Word40 X_shr_r( Word40 X_var1,  Word16 var2) {
  return (((var2)>0)?X_add(X_shr((X_var1),(var2)),X_set(0,X_shr((X_var1),(Word16)((var2)-1)).body&1)):X_shr((X_var1),(var2))) ;
}

#endif
#endif
#endif

#ifdef __cplusplus
	}
#endif

# pragma reject_floats reset
#endif
