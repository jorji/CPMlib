/*
###################################################################################
#
# CPMlib - Computational space Partitioning Management library
#
# Copyright (c) 2012-2014 Institute of Industrial Science (IIS), The University of Tokyo.
# All rights reserved.
#
# Copyright (c) 2014-2016 Advanced Institute for Computational Science (AICS), RIKEN.
# All rights reserved.
#
# Copyright (c) 2016-2017 Research Institute for Information Technology (RIIT), Kyushu University.
# All rights reserved.
#
###################################################################################
 */

/**
 * @file   cpm_Define.h
 * CPMの定義マクロ記述ヘッダーファイル
 * @date   2012/05/31
 */
#ifndef _CPM_DEFINE_H_
#define _CPM_DEFINE_H_

#ifndef DISABLE_MPI
#include "mpi.h"
#else
#include "cpm_mpistub.h"
#endif

#if defined(_BUFSIZE_LONG_DOUBLE_)
  #define REAL_BUF_TYPE long double
#elif defined(_BUFSIZE_FLOAT_)
  #define REAL_BUF_TYPE float
#else
  /** 袖通信バッファの型指定
   *  - デフォルトでは、REAL_BUF_TYPE=double
   *  - コンパイル時オプション-D_BUFSIZE_FLOAT_を付与することで
   *    REAL_BUF_TYPE=floatになる
   *  - コンパイル時オプション-D_BUFSIZE_LONG_DOUBLE_を付与することで
   *    REAL_BUF_TYPE=long doubleになる
   */
  #define REAL_BUF_TYPE double
#endif


/** 3次元インデクス(i,j,k) -> 1次元インデクス変換マクロ
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @return 1次元インデクス
 */
#define _IDX_S3D(_I,_J,_K,_NI,_NJ,_NK,_VC) \
( (long long)(_K+(_VC)) * (long long)(_NI+2*(_VC)) * (long long)(_NJ+2*(_VC)) \
+ (long long)(_J+(_VC)) * (long long)(_NI+2*(_VC)) \
+ (long long)(_I+(_VC)) \
)

/** 3次元インデクス(i,j,k) -> 1次元インデクス変換マクロ(パディング対応)
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @param[in] _IP i方向パディング数
 *  @param[in] _JP j方向パディング数
 *  @param[in] _KP k方向パディング数
 *  @return 1次元インデクス
 */
#define _IDX_S3D_PAD(_I,_J,_K,_NI,_NJ,_NK,_VC,_IP,_JP,_KP) \
( (long long)(_K+_VC) * (long long)(_NI+2*(_VC)+_IP) * (long long)(_NJ+2*(_VC)+_JP) \
+ (long long)(_J+_VC) * (long long)(_NI+2*(_VC)+_IP) \
+ (long long)(_I+_VC) \
)

/** 4次元インデクス(i,j,k,n) -> 1次元インデクス変換マクロ
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _N  成分インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @return 1次元インデクス
 */
#define _IDX_S4D(_I,_J,_K,_N,_NI,_NJ,_NK,_VC) \
( (long long)(_N) * (long long)(_NI+2*(_VC)) * (long long)(_NJ+2*(_VC)) * (long long)(_NK+2*(_VC)) \
+ _IDX_S3D(_I,_J,_K,_NI,_NJ,_NK,_VC) \
)

/** 4次元インデクス(i,j,k,n) -> 1次元インデクス変換マクロ(パディング対応)
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _N  成分インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @param[in] _IP i方向パディング数
 *  @param[in] _JP j方向パディング数
 *  @param[in] _KP k方向パディング数
 *  @return 1次元インデクス
 */
#define _IDX_S4D_PAD(_I,_J,_K,_N,_NI,_NJ,_NK,_VC,_IP,_JP,_KP) \
( (long long)(_N) * (long long)(_NI+2*(_VC)+_IP) * (long long)(_NJ+2*(_VC)+_JP) * (long long)(_NK+2*(_VC)+_KP) \
+ _IDX_S3D_PAD(_I,_J,_K,_NI,_NJ,_NK,_VC,_IP,_JP,_KP) \
)

/** 3次元インデクス(i,j,k,3) -> 1次元インデクス変換マクロ
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _N  成分インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 */
#define _IDX_V3D(_I,_J,_K,_N,_NI,_NJ,_NK,_VC) (_IDX_S4D(_I,_J,_K,_N,_NI,_NJ,_NK,_VC))

/** 3次元インデクス(i,j,k,3) -> 1次元インデクス変換マクロ(パディング対応)
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _N  成分インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @param[in] _IP i方向パディング数
 *  @param[in] _JP j方向パディング数
 *  @param[in] _KP k方向パディング数
 */
#define _IDX_V3D_PAD(_I,_J,_K,_N,_NI,_NJ,_NK,_VC,_IP,_JP,_KP) (_IDX_S4D_PAD(_I,_J,_K,_N,_NI,_NJ,_NK,_VC,_IP,_JP,_KP))

/** 4次元インデクス(n,i,j,k) -> 1次元インデクス変換マクロ
 *  @param[in] _N  成分インデクス
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _NN 成分数
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @return 1次元インデクス
 */
#define _IDX_S4DEX(_N,_I,_J,_K,_NN,_NI,_NJ,_NK,_VC) \
( (long long)(_NN) * _IDX_S3D(_I,_J,_K,_NI,_NJ,_NK,_VC) \
+ (long long)(_N) )

/** 4次元インデクス(n,i,j,k) -> 1次元インデクス変換マクロ(パディング対応)
 *  @param[in] _N  成分インデクス
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _NN 成分数
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @param[in] _NP 成分パディング数
 *  @param[in] _IP i方向パディング数
 *  @param[in] _JP j方向パディング数
 *  @param[in] _KP k方向パディング数
 *  @return 1次元インデクス
 */
#define _IDX_S4DEX_PAD(_N,_I,_J,_K,_NN,_NI,_NJ,_NK,_VC,_NP,_IP,_JP,_KP) \
( (long long)(_NN+_NP) * _IDX_S3D_PAD(_I,_J,_K,_NI,_NJ,_NK,_VC,_IP,_JP,_KP) \
+ (long long)(_N) )

/** 3次元インデクス(3,i,j,k) -> 1次元インデクス変換マクロ
 *  @param[in] _N  成分インデクス
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @return 1次元インデクス
 */
#define _IDX_V3DEX(_N,_I,_J,_K,_NI,_NJ,_NK,_VC) (_IDX_S4DEX(_N,_I,_J,_K,3,_NI,_NJ,_NK,_VC))

/** 3次元インデクス(3,i,j,k) -> 1次元インデクス変換マクロ(パディング対応)
 *  @param[in] _N  成分インデクス
 *  @param[in] _I  i方向インデクス
 *  @param[in] _J  j方向インデクス
 *  @param[in] _K  k方向インデクス
 *  @param[in] _NI i方向インデクスサイズ
 *  @param[in] _NJ j方向インデクスサイズ
 *  @param[in] _NK k方向インデクスサイズ
 *  @param[in] _VC 仮想セル数
 *  @param[in] _NP 成分パディング数
 *  @param[in] _IP i方向パディング数
 *  @param[in] _JP j方向パディング数
 *  @param[in] _KP k方向パディング数
 *  @return 1次元インデクス
 */
#define _IDX_V3DEX_PAD(_N,_I,_J,_K,_NI,_NJ,_NK,_VC,_NP,_IP,_JP,_KP) (_IDX_S4DEX_PAD(_N,_I,_J,_K,3,_NI,_NJ,_NK,_VC,_NP,_IP,_JP,_KP))

// 2016/01/22 FESAT add.s
/** 定義点タイプ */
enum cpm_DefPointType
{
  CPM_DEFPOINTTYPE_UNKNOWN = -1 ///< 未定義
, CPM_DEFPOINTTYPE_FVM     = 0  ///< ボクセル
, CPM_DEFPOINTTYPE_FDM     = 1  ///< ノード
};
// 2016/01/22 FEAST add.e

/** 領域分割タイプ */
enum cpm_DomainType
{
  CPM_DOMAIN_UNKNOWN   = -1  ///< 未定義
, CPM_DOMAIN_CARTESIAN = 0   ///< カーテシアン
, CPM_DOMAIN_LMR       = 1   ///< LMR(Local Mesh Refinement)
};

/** 面フラグ */
enum cpm_FaceFlag
{
  X_MINUS = 0  ///< -X face
, X_PLUS  = 1  ///< +X face
, Y_MINUS = 2  ///< -Y face
, Y_PLUS  = 3  ///< +Y face
, Z_MINUS = 4  ///< -Z face
, Z_PLUS  = 5  ///< +Z face
};

/** 軸方向フラグ */
enum cpm_DirFlag
{
  X_DIR = 0 ///< X direction
, Y_DIR = 1 ///< Y direction
, Z_DIR = 2 ///< Z direction
};

/** 方向フラグ */
enum cpm_PMFlag
{
  PLUS2MINUS = 0 ///< plus   -> minus direction
, MINUS2PLUS = 1 ///< minus  -> plus  direction
, BOTH       = 2 ///< plus  <-> minus direction
};

/** 自動分割ポリシー */
enum cpm_DivPolicy
{
  DIV_COMM_SIZE = 0 ///< 通信面総数が小さくなるように
, DIV_VOX_CUBE  = 1 ///< サブドメインが立方体に近くなるように
};

/** CPMのエラーコード */
enum cpm_ErrorCode
{
  CPM_SUCCESS                     = 0    ///< 正常終了

, CPM_ERROR                       = 1000 ///< その他のエラー
, CPM_ERROR_PM_INSTANCE           = 1001 ///< 並列管理クラスcpm_ParaManagerのインスタンス失敗
, CPM_ERROR_INVALID_PTR           = 1002 ///< ポインタのエラー
, CPM_ERROR_INVALID_DOMAIN_NO     = 1003 ///< 領域番号が不正
, CPM_ERROR_INVALID_OBJKEY        = 1004 ///< 指定登録番号のオブジェクトが存在しない
, CPM_ERROR_REGIST_OBJKEY         = 1005 ///< オブジェクト登録に失敗:

, CPM_ERROR_TEXTPARSER            = 2000 ///< テキストパーサーに関するエラー
, CPM_ERROR_NO_TEXTPARSER         = 2001 ///< テキストパーサーを組み込んでいない
, CPM_ERROR_TP_NOVECTOR           = 2002 ///< 領域分割情報ファイルのベクトルデータ読み込みエラー
, CPM_ERROR_TP_VECTOR_SIZE        = 2003 ///< 領域分割情報ファイルのベクトルデータのサイズが不正
, CPM_ERROR_TP_INVALID_G_ORG      = 2004 ///< 領域分割情報ファイルのドメイン原点情報が不正
, CPM_ERROR_TP_INVALID_G_VOXEL    = 2005 ///< 領域分割情報ファイルのドメインVOXEL数情報が不正
, CPM_ERROR_TP_INVALID_G_PITCH    = 2006 ///< 領域分割情報ファイルのドメインピッチ情報が不正
, CPM_ERROR_TP_INVALID_G_RGN      = 2007 ///< 領域分割情報ファイルのドメイン空間サイズ情報が不正
, CPM_ERROR_TP_INVALID_G_DIV      = 2008 ///< 領域分割情報ファイルのドメイン領域分割数情報が不正
, CPM_ERROR_TP_INVALID_POS        = 2009 ///< 領域分割情報ファイルのサブドメイン位置情報が不正

, CPM_ERROR_TP_LMR_DOMAINFILE     = 2100 ///< LMR領域分割情報ファイルの読み込みエラー
, CPM_ERROR_TP_LMR_DOMAIN         = 2101 ///< LMR領域分割情報ファイルのDomainブロック読み込みエラー
, CPM_ERROR_TP_LMR_BCMTREE        = 2102 ///< LMR領域分割情報ファイルのBCMTreeブロック読み込みエラー
, CPM_ERROR_TP_LMR_LEAFBLOCK      = 2103 ///< LMR領域分割情報ファイルのLeafBlock読み込みエラー
, CPM_ERROR_TP_LMR_UNIT           = 2104 ///< LMR領域分割情報ファイルのLeafBlock/Unit読み込みエラー
, CPM_ERROR_TP_LMR_SIZE_NOT_EVEN  = 2105 ///< LMR領域分割情報ファイルのLeafBlock/Sizeが偶数でない

, CPM_ERROR_VOXELINIT             = 3000 ///< VoxelInitでエラー
, CPM_ERROR_NOT_IN_PROCGROUP      = 3001 ///< 自ランクがプロセスグループに含まれていない
, CPM_ERROR_ALREADY_VOXELINIIT    = 3002 ///< 指定されたプロセスグループが既に領域分割済み:
, CPM_ERROR_MISMATCH_NP_SUBDOMAIN = 3003 ///< 並列数とサブドメイン数が一致していない
, CPM_ERROR_CREATE_RANKMAP        = 3004 ///< ランクマップ生成に失敗
, CPM_ERROR_CREATE_NEIGHBOR       = 3005 ///< 隣接ランク情報生成に失敗
, CPM_ERROR_CREATE_LOCALDOMAIN    = 3006 ///< ローカル領域情報生成に失敗
, CPM_ERROR_INSERT_VOXELMAP       = 3007 ///< 領域情報のマップへの登録失敗
, CPM_ERROR_CREATE_PROCGROUP      = 3008 ///< プロセスグループ生成に失敗
, CPM_ERROR_INVALID_VOXELSIZE     = 3009 ///< VOXEL数が不正
, CPM_ERROR_INVALID_REGION        = 3010 ///< 全体空間サイズが不正
, CPM_ERROR_INVALID_DIVNUM        = 3011 ///< 領域分割数が不正
, CPM_ERROR_OPEN_SBDM             = 3012 ///< ActiveSubdomainファイルのオープンに失敗
, CPM_ERROR_READ_SBDM_HEADER      = 3013 ///< ActiveSubdomainファイルのヘッダー読み込みに失敗
, CPM_ERROR_READ_SBDM_FORMAT      = 3014 ///< ActiveSubdomainファイルのフォーマットエラー
, CPM_ERROR_READ_SBDM_DIV         = 3015 ///< ActiveSubdomainファイルの領域分割数読み込みに失敗
, CPM_ERROR_READ_SBDM_CONTENTS    = 3016 ///< ActiveSubdomainファイルのContents読み込みに失敗
, CPM_ERROR_SBDM_NUMDOMAIN_ZERO   = 3017 ///< ActiveSubdomainファイルの活性ドメイン数が0
, CPM_ERROR_MISMATCH_DIV_SUBDOMAIN = 3018 ///< 領域分割数がActiveSubdomainファイルと一致していない
, CPM_ERROR_DECIDE_DIV_PATTERN    = 3019 ///< 自動領域分割が不可能なパターン

// 2016/01/22 FEAST add.s
, CPM_ERROR_ALREADY_NODEINIT         = 3020 ///< 指定されたプロセスグループが既に領域分割済み:
, CPM_ERROR_INVALID_NODESIZE         = 3021 ///< 頂点数が不正
, CPM_ERROR_INSERT_DEFPOINTTYPEMAP   = 3022 ///< 定義点管理のマップへの登録失敗
// 2016/01/22 FEAST adde

, CPM_ERROR_DOMAINTYPE_VOXELINIT     = 3100 ///< 領域分割タイプと対応しないVoxelInitがコールされた
, CPM_ERROR_DOMAINTYPE_SETBNDCOMMBUF = 3101 ///< 領域分割タイプと対応しないSetBndCommBufferがコールされた

// 2016/01/22 FEAST add.s
, CPM_ERROR_DOMAINTYPE_NODEINIT      = 3102 ///< 領域分割タイプと対応しないNodeInitがコールされた
// 2016/01/22 FEAST add.e

, CPM_ERROR_VOXELINIT_LMR         = 3200 ///< VoxelInit_LMRでエラー
, CPM_ERROR_LMR_OPEN_OCTFILE      = 3201 ///< LMR用木情報ファイルオープンエラー
, CPM_ERROR_LMR_INVALID_OCTFILE   = 3202 ///< LMR用木情報ファイルのエンディアン識別子が不正
, CPM_ERROR_LMR_READ_OCT_HEADER   = 3203 ///< LMR用木情報ファイルのヘッダー情報読み込みエラー
, CPM_ERROR_LMR_READ_OCT_PEDIGREE = 3204 ///< LMR用木情報ファイルのぺディグリー情報読み込みエラー
, CPM_ERROR_LMR_MISMATCH_NP_NUMLEAF = 3205 ///< LMRでリーフ数と並列数が一致しない

, CPM_ERROR_GET_INFO              = 4000 ///< 情報取得系関数でエラー
, CPM_ERROR_GET_DIVNUM            = 4001 ///< 領域分割数の取得エラー
, CPM_ERROR_GET_PITCH             = 4002 ///< ピッチの取得エラー
, CPM_ERROR_GET_GLOBALVOXELSIZE   = 4003 ///< 全体ボクセル数の取得エラー
, CPM_ERROR_GET_GLOBALORIGIN      = 4004 ///< 全体空間の原点の取得エラー
, CPM_ERROR_GET_GLOBALREGION      = 4005 ///< 全体空間サイズの取得エラー
, CPM_ERROR_GET_LOCALVOXELSIZE    = 4006 ///< 自ランクのボクセル数の取得エラー
, CPM_ERROR_GET_LOCALORIGIN       = 4007 ///< 自ランクの空間原点の取得エラー
, CPM_ERROR_GET_LOCALREGION       = 4008 ///< 自ランクの空間サイズの取得エラー
, CPM_ERROR_GET_DIVPOS            = 4009 ///< 自ランクの領域分割位置の取得エラー
, CPM_ERROR_GET_HEADINDEX         = 4011 ///< 始点インデクスの取得エラー
, CPM_ERROR_GET_TAILINDEX         = 4012 ///< 終点インデクスの取得エラー
, CPM_ERROR_GET_NEIGHBOR_RANK     = 4013 ///< 隣接ランク番号の取得エラー
, CPM_ERROR_GET_PERIODIC_RANK     = 4014 ///< 周期境界位置の隣接ランク番号の取得エラー

, CPM_ERROR_GET_MYRANK            = 4015 ///< ランク番号の取得エラー
, CPM_ERROR_GET_NUMRANK           = 4016 ///< ランク数の取得エラー

// 2016/01/22 FEAST add.s
, CPM_ERROR_GET_GLOBALNODESIZE    = 4017 ///< 全体頂点数の取得エラー
, CPM_ERROR_GET_GLOBALARRAYSIZE   = 4018 ///< 全体ボクセル数または頂点数の取得エラー
, CPM_ERROR_GET_LOCALNODESIZE     = 4019 ///< 自ランクの頂点数の取得エラー
, CPM_ERROR_GET_LOCALARRAYSIZE    = 4020 ///< 自ランクのボクセル数または頂点数の取得エラー
// 2016/01/22 FEAST add.e

, CPM_ERROR_MPI                   = 9000 ///< MPIのエラー
, CPM_ERROR_NO_MPI_INIT           = 9001 ///< MPI_Initがコールされていない
, CPM_ERROR_MPI_BARRIER           = 9003 ///< MPI_Barrierでエラー
, CPM_ERROR_MPI_BCAST             = 9004 ///< MPI_Bcastでエラー
, CPM_ERROR_MPI_SEND              = 9005 ///< MPI_Sendでエラー
, CPM_ERROR_MPI_RECV              = 9006 ///< MPI_Recvでエラー
, CPM_ERROR_MPI_ISEND             = 9007 ///< MPI_Isendでエラー
, CPM_ERROR_MPI_IRECV             = 9008 ///< MPI_Irecvでエラー
, CPM_ERROR_MPI_WAIT              = 9009 ///< MPI_Waitでエラー
, CPM_ERROR_MPI_WAITALL           = 9010 ///< MPI_Waitallでエラー
, CPM_ERROR_MPI_ALLREDUCE         = 9011 ///< MPI_Allreduceでエラー
, CPM_ERROR_MPI_GATHER            = 9012 ///< MPI_Gatherでエラー
, CPM_ERROR_MPI_ALLGATHER         = 9013 ///< MPI_Allgatherでエラー
, CPM_ERROR_MPI_GATHERV           = 9014 ///< MPI_Gathervでエラー
, CPM_ERROR_MPI_ALLGATHERV        = 9015 ///< MPI_Allgathervでエラー
, CPM_ERROR_MPI_DIMSCREATE        = 9016 ///< MPI_Dims_createでエラー

, CPM_ERROR_BNDCOMM               = 9500 ///< BndCommでエラー
, CPM_ERROR_BNDCOMM_VOXELSIZE     = 9501 ///< VoxelSize取得でエラー
, CPM_ERROR_BNDCOMM_BUFFER        = 9502 ///< 袖通信バッファ取得でエラー
, CPM_ERROR_BNDCOMM_BUFFERLENGTH  = 9503 ///< 袖通信バッファサイズが足りない
, CPM_ERROR_BNDCOMM_ALLOC_BUFFER  = 9504 ///< 袖通信バッファ領域確保でエラー

, CPM_ERROR_PERIODIC              = 9600 ///< PeriodicCommでエラー
, CPM_ERROR_PERIODIC_INVALID_DIR  = 9601 ///< 不正な軸方向フラグが指定された
, CPM_ERROR_PERIODIC_INVALID_PM   = 9602 ///< 不正な正負方向フラグが指定された

, CPM_ERROR_MPI_INVALID_COMM      = 9100 ///< MPIコミュニケータが不正
, CPM_ERROR_MPI_INVALID_DATATYPE  = 9101 ///< 対応しない型が指定された
, CPM_ERROR_MPI_INVALID_OPERATOR  = 9102 ///< 対応しないオペレータが指定された
, CPM_ERROR_MPI_INVALID_REQUEST   = 9103 ///< 不正なリクエストが指定された
};

/** fortran用のデータタイプ */
enum CPM_Datatype
{
  CPM_CHAR               =  1 ///< char
, CPM_UNSIGNED_CHAR      =  2 ///< unsigned char
, CPM_BYTE               =  3 ///< byte(not support)
, CPM_SHORT              =  4 ///< short
, CPM_UNSIGNED_SHORT     =  5 ///< unsigned short
, CPM_INT                =  6 ///< int
, CPM_UNSIGNED           =  7 ///< unsigned
, CPM_LONG               =  8 ///< long
, CPM_UNSIGNED_LONG      =  9 ///< unsigned long
, CPM_FLOAT              = 10 ///< float
, CPM_DOUBLE             = 11 ///< double
, CPM_LONG_DOUBLE        = 12 ///< long double
#ifdef MPI_LONG_LONG_INT
, CPM_LONG_LONG_INT      = 13 ///< long long int
#endif
#ifdef MPI_LONG_LONG
, CPM_LONG_LONG          = 13 ///< long long
#endif
#ifdef MPI_UNSIGNED_LONG_LONG
, CPM_UNSIGNED_LONG_LONG = 51 ///< unsigned long long
#endif
, CPM_REAL               = 52 ///< REAL_TYPE
};

/** fortran用のオペレータ */
enum CPM_Op
{
  CPM_MAX    = 100 ///< 最大値
, CPM_MIN    = 101 ///< 最小値
, CPM_SUM    = 102 ///< 和
, CPM_PROD   = 103 ///< 積
, CPM_LAND   = 104 ///< 論理積
, CPM_BAND   = 105 ///< ビット演算の積
, CPM_LOR    = 106 ///< 論理和
, CPM_BOR    = 107 ///< ビット演算の和
, CPM_LXOR   = 108 ///< 排他的論理和
, CPM_BXOR   = 109 ///< ビット演算の排他的論理和
, CPM_MINLOC = 110 ///< 最大値と位置(not support)
, CPM_MAXLOC = 111 ///< 最小値と位置(not support)
};

/** 配列形状タイプ */
enum CPM_ARRAY_SHAPE
{
  CPM_ARRAY_UNKNOWN = -1 ///< 不定
, CPM_ARRAY_S3D     = 0  ///< Scalar3D   {imax,jmax,kmax}
, CPM_ARRAY_V3D     = 1  ///< Vector3D   {imax,jmax,kmax,3}
, CPM_ARRAY_V3DEX   = 2  ///< Vector3DEx {3,imax,jmax,kmax}
, CPM_ARRAY_S4D     = 3  ///< Scalar4D   {imax,jmax,kmax,n}
, CPM_ARRAY_S4DEX   = 4  ///< Scalar4DEx {n,imax,jmax,kmax}
};

enum CPM_PADDING
{
  CPM_PADDING_ON  = true,
  CPM_PADDING_OFF = false,
};

/** デバッグライト用 */
#ifndef stmpd_printf
  #define stmpd_printf printf("%s (%d):  ",__FILE__, __LINE__); printf
#endif

#endif /* _CPM_DEFINE_H_ */
