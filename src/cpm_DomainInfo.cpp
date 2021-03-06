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
 * @file   cpm_DomainInfo.cpp
 * DomainInfoクラスのソースファイル
 * @date   2012/05/31
 */
#include "cpm_DomainInfo.h"

////////////////////////////////////////////////////////////////////////////////
// コンストラクタ
cpm_DomainInfo::cpm_DomainInfo()
  : cpm_Base()
{
  clear();
}

////////////////////////////////////////////////////////////////////////////////
// デストラクタ
cpm_DomainInfo::~cpm_DomainInfo()
{
}

////////////////////////////////////////////////////////////////////////////////
// 情報のクリア
void
cpm_DomainInfo::clear()
{
  for( int i=0;i<3;i++ )
  {
    m_origin[i] = 0.0;
    m_region[i] = 0.0;
    m_pitch[i]  = 0.0;
    m_voxNum[i] = 0;
// 2016/01/22 FEAST add.s
    m_nodNum[i] = 0;
// 2016/01/22 FEAST add.e

  }
}

////////////////////////////////////////////////////////////////////////////////
// 原点のセット
void
cpm_DomainInfo::SetOrigin( double org[3] )
{
  m_origin[0] = org[0];
  m_origin[1] = org[1];
  m_origin[2] = org[2];
}

////////////////////////////////////////////////////////////////////////////////
// 原点の取得
const double*
cpm_DomainInfo::GetOrigin() const
{
  return m_origin;
}

////////////////////////////////////////////////////////////////////////////////
// ピッチのセット
void
cpm_DomainInfo::SetPitch( double pch[3] )
{
  m_pitch[0] = pch[0];
  m_pitch[1] = pch[1];
  m_pitch[2] = pch[2];
}

////////////////////////////////////////////////////////////////////////////////
// ピッチの取得
const double*
cpm_DomainInfo::GetPitch() const
{
  return m_pitch;
}

////////////////////////////////////////////////////////////////////////////////
// 空間サイズのセット
void
cpm_DomainInfo::SetRegion( double rgn[3] )
{
  m_region[0] = rgn[0];
  m_region[1] = rgn[1];
  m_region[2] = rgn[2];
}

////////////////////////////////////////////////////////////////////////////////
// 空間サイズの取得
const double*
cpm_DomainInfo::GetRegion() const
{
  return m_region;
}

////////////////////////////////////////////////////////////////////////////////
// VOXEL数のセット
void
cpm_DomainInfo::SetVoxNum( int vox[3] )
{
  m_voxNum[0] = vox[0];
  m_voxNum[1] = vox[1];
  m_voxNum[2] = vox[2];

// 2016/01/22 FEAST add.s
  m_nodNum[0] = vox[0] + 1;
  m_nodNum[1] = vox[1] + 1;
  m_nodNum[2] = vox[2] + 1;
// 2016/01/22 FEAST add.e
}

////////////////////////////////////////////////////////////////////////////////
// VOXEL数の取得
const int*
cpm_DomainInfo::GetVoxNum() const
{
  return m_voxNum;
}

// 2016/01/22 FEAST add.s
////////////////////////////////////////////////////////////////////////////////
// 頂点数のセット
void
cpm_DomainInfo::SetNodNum( int nod[3] )
{
  m_nodNum[0] = nod[0];
  m_nodNum[1] = nod[1];
  m_nodNum[2] = nod[2];

  m_voxNum[0] = nod[0] - 1;
  m_voxNum[1] = nod[1] - 1;
  m_voxNum[2] = nod[2] - 1;
}

////////////////////////////////////////////////////////////////////////////////
// 頂点数の取得
const int*
cpm_DomainInfo::GetNodNum() const
{
  return m_nodNum;
}
// 2016/01/22 FEAST add.e

////////////////////////////////////////////////////////////////////////////////
// 領域情報のチェック
cpm_ErrorCode cpm_DomainInfo::CheckData()
{
  if( m_region[0] <= 0.0 || m_region[1] <= 0.0 || m_region[2] <= 0.0 )
  {
    return CPM_ERROR_INVALID_REGION;
  }
  if( m_voxNum[0] <= 0 || m_voxNum[1] <=0 || m_voxNum[2] <= 0 )
  {
    return CPM_ERROR_INVALID_VOXELSIZE;
  }

  return CPM_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
// デフォルトコンストラクタ
cpm_ActiveSubdomainInfo::cpm_ActiveSubdomainInfo()
  : cpm_Base()
{
  clear();
}

////////////////////////////////////////////////////////////////////////////////
// コンストラクタ
cpm_ActiveSubdomainInfo::cpm_ActiveSubdomainInfo( int pos[3] )
  : cpm_Base()
{
  SetPos(pos);
}

////////////////////////////////////////////////////////////////////////////////
// デストラクタ
cpm_ActiveSubdomainInfo::~cpm_ActiveSubdomainInfo()
{
}

////////////////////////////////////////////////////////////////////////////////
// 情報のクリア
void
cpm_ActiveSubdomainInfo::clear()
{
  m_pos[0] = 0;
  m_pos[1] = 0;
  m_pos[2] = 0;
}

////////////////////////////////////////////////////////////////////////////////
// 位置情報のセット
void
cpm_ActiveSubdomainInfo::SetPos( int pos[3] )
{
  m_pos[0] = pos[0];
  m_pos[1] = pos[1];
  m_pos[2] = pos[2];
}

////////////////////////////////////////////////////////////////////////////////
// 位置情報の取得
const int*
cpm_ActiveSubdomainInfo::GetPos() const
{
  return m_pos;
}

////////////////////////////////////////////////////////////////////////////////
// 比較演算子
bool
cpm_ActiveSubdomainInfo::operator==( cpm_ActiveSubdomainInfo dom )
{
  if( m_pos[0] != dom.m_pos[0] ) return false;
  if( m_pos[1] != dom.m_pos[1] ) return false;
  if( m_pos[2] != dom.m_pos[2] ) return false;
  return true;
}

////////////////////////////////////////////////////////////////////////////////
// 比較演算子
bool
cpm_ActiveSubdomainInfo::operator!=( cpm_ActiveSubdomainInfo dom )
{
  if( m_pos[0] == dom.m_pos[0] ) return false;
  if( m_pos[1] == dom.m_pos[1] ) return false;
  if( m_pos[2] == dom.m_pos[2] ) return false;
  return true;
}

////////////////////////////////////////////////////////////////////////////////
// コンストラクタ
cpm_GlobalDomainInfo::cpm_GlobalDomainInfo()
  : cpm_DomainInfo()
{
  clear();
}

////////////////////////////////////////////////////////////////////////////////
// デストラクタ
cpm_GlobalDomainInfo::~cpm_GlobalDomainInfo()
{
}

////////////////////////////////////////////////////////////////////////////////
// 情報のクリア
void
cpm_GlobalDomainInfo::clear()
{
  cpm_DomainInfo::clear();
  for( int i=0;i<3;i++ )
  {
    m_divNum[i] = 0;
  }
  m_subDomainInfo.clear();
}

////////////////////////////////////////////////////////////////////////////////
// 領域分割数のセット
void
cpm_GlobalDomainInfo::SetDivNum( int div[3] )
{
  m_divNum[0] = div[0];
  m_divNum[1] = div[1];
  m_divNum[2] = div[2];
}

////////////////////////////////////////////////////////////////////////////////
// 領域分割数の取得
const int*
cpm_GlobalDomainInfo::GetDivNum() const
{
  return m_divNum;
}

////////////////////////////////////////////////////////////////////////////////
// 活性サブドメイン情報の存在チェック
bool
cpm_GlobalDomainInfo::IsExistSubdomain( cpm_ActiveSubdomainInfo subDomain )
{
  for( size_t i=0;i<m_subDomainInfo.size();i++ )
  {
    cpm_ActiveSubdomainInfo dom = m_subDomainInfo[i];
    if( dom == subDomain ) return true;
  }
  return false;
}

////////////////////////////////////////////////////////////////////////////////
// 活性サブドメイン情報の追加
bool
cpm_GlobalDomainInfo::AddSubdomain( cpm_ActiveSubdomainInfo subDomain )
{
  //既存チェック
  if( IsExistSubdomain(subDomain) ) return false;

  //追加
  m_subDomainInfo.push_back(subDomain);
  return true;
}

////////////////////////////////////////////////////////////////////////////////
// 活性サブドメインの数を取得
int
cpm_GlobalDomainInfo::GetSubdomainNum() const
{
  if( m_subDomainInfo.size() > 0 )
  {
    return (int)m_subDomainInfo.size();
  }
  if( m_divNum[0] <= 0 || m_divNum[1] <= 0 || m_divNum[2] <= 0 )
  {
    return 0;
  }
  return m_divNum[0] * m_divNum[1] * m_divNum[2];
}

////////////////////////////////////////////////////////////////////////////////
// 活性サブドメインの数を取得(情報数)
int
cpm_GlobalDomainInfo::GetSubdomainArraySize() const
{
  return (int)m_subDomainInfo.size();
}

////////////////////////////////////////////////////////////////////////////////
// 活性サブドメイン情報を取得
const cpm_ActiveSubdomainInfo*
cpm_GlobalDomainInfo::GetSubdomainInfo( size_t idx ) const
{
  if( int(idx) >= GetSubdomainNum() ) return NULL;
  return &(m_subDomainInfo[idx]);
}

////////////////////////////////////////////////////////////////////////////////
// 領域情報のチェック
cpm_ErrorCode cpm_GlobalDomainInfo::CheckData( int nRank )
{
  cpm_ErrorCode ret;

  // 親クラス
  if( (ret = cpm_DomainInfo::CheckData()) != CPM_SUCCESS )
  {
    return ret;
  }

  // 領域分割数
  if( m_divNum[0] <= 0 || m_divNum[1] <= 0 || m_divNum[2] <= 0 )
  {
    return CPM_ERROR_INVALID_DIVNUM;
  }

  // 活性サブドメイン情報
  int ndom = m_subDomainInfo.size();
  if( ndom == 0 )
  {
    //活性サブドメイン情報が空のとき、全領域を活性サブドメインとする
    if( nRank != m_divNum[0]*m_divNum[1]*m_divNum[2] )
    {
      return CPM_ERROR_MISMATCH_NP_SUBDOMAIN;
    }
    for( int k=0;k<m_divNum[2];k++ ){
    for( int j=0;j<m_divNum[1];j++ ){
    for( int i=0;i<m_divNum[0];i++ ){
      int pos[3] = {i,j,k};
      cpm_ActiveSubdomainInfo dom( pos );
      AddSubdomain( dom );
    }}}
  }
  else
  {
    if( nRank != ndom )
    {
      return CPM_ERROR_MISMATCH_NP_SUBDOMAIN;
    }
  }

  return CPM_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
// ActiveSubdomainファイルのエンディアンチェック
CPM_ENDIAN::EMatchType
cpm_GlobalDomainInfo::isMatchEndianSbdmMagick( int ident )
{
  char magick_c[] = "SBDM";
  int  magick_i=0;

  // check match
  magick_i = (magick_c[3]<<24) + (magick_c[2]<<16) + (magick_c[1]<<8) + magick_c[0];
  if( magick_i == ident )
  {
    return CPM_ENDIAN::Match;
  }

  // check unmatch
  magick_i = (magick_c[0]<<24) + (magick_c[1]<<16) + (magick_c[2]<<8) + magick_c[3];
  if( magick_i == ident )
  {
    return CPM_ENDIAN::UnMatch;
  }

  // unknown format
  return CPM_ENDIAN::UnKnown;
}

////////////////////////////////////////////////////////////////////////////////
// ActiveSubdomainファイルの読み込み
cpm_ErrorCode
cpm_GlobalDomainInfo::ReadActiveSubdomainFile
(
  std::string subDomainFile
)
{
  // 読み込み
  int div[3];
  cpm_ErrorCode ret = cpm_GlobalDomainInfo::ReadActiveSubdomainFile( subDomainFile, m_subDomainInfo, div );
  if( ret != CPM_SUCCESS )
  {
    return ret;
  }

  // 領域分割数のチェック
  if( m_divNum[0] > 0 && m_divNum[1] > 0 && m_divNum[2] > 0 )
  {
    if( div[0] != m_divNum[0] || div[0] != m_divNum[0] ||div[0] != m_divNum[0] )
    {
      return CPM_ERROR_MISMATCH_DIV_SUBDOMAIN;
    }
  }

  return CPM_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
// ActiveSubdomainファイルの読み込み(static関数)
cpm_ErrorCode
cpm_GlobalDomainInfo::ReadActiveSubdomainFile
(
  std::string subDomainFile
, std::vector<cpm_ActiveSubdomainInfo>& subDomainInfo
, int div[3]
)
{
  if( subDomainFile.empty() )
  {
    return CPM_ERROR_OPEN_SBDM;
  }

  // ファイルオープン
  FILE *fp = fopen( subDomainFile.c_str(), "rb" );
  if( !fp )
  {
    return CPM_ERROR_OPEN_SBDM;
  }

  // エンディアン識別子
  int ident;
  if( fread( &ident, sizeof(int), 1, fp ) != 1 )
  {
    fclose(fp);
    return CPM_ERROR_READ_SBDM_HEADER;
  }
  CPM_ENDIAN::EMatchType endian = isMatchEndianSbdmMagick( ident );
  if( endian == CPM_ENDIAN::UnKnown )
  {
    fclose(fp);
    return CPM_ERROR_READ_SBDM_FORMAT;
  }

  // 領域分割数
  if( fread( div, sizeof(int), 3, fp ) != 3 )
  {
    fclose(fp);
    return CPM_ERROR_READ_SBDM_DIV;
  }
  if( endian == CPM_ENDIAN::UnMatch )
  {
    CPM_ENDIAN::BSWAPVEC(div,3);
  }

  // contents
  size_t nc = size_t(div[0]) * size_t(div[1]) * size_t(div[2]);
  unsigned char *contents = new unsigned char[nc];
  if( fread( contents, sizeof(unsigned char), nc, fp ) != nc )
  {
    delete [] contents;
    fclose(fp);
    return CPM_ERROR_READ_SBDM_CONTENTS;
  }

  // ファイルクローズ
  fclose(fp);

  size_t ptr = 0;
  // 活性ドメイン情報の生成
  for( int k=0;k<div[2];k++ ){
  for( int j=0;j<div[1];j++ ){
  for( int i=0;i<div[0];i++ ){
    if( contents[ptr] == 0x01 )
    {
      int pos[3] = {i,j,k};
      cpm_ActiveSubdomainInfo dom( pos );
      subDomainInfo.push_back(dom);
    }
    ptr++;
  }}}

  // contentsのdelete
  delete [] contents;

  // 活性ドメインの数をチェック
  if( subDomainInfo.size() == 0 )
  {
    return CPM_ERROR_SBDM_NUMDOMAIN_ZERO;
  }

  return CPM_SUCCESS;
}


////////////////////////////////////////////////////////////////////////////////
// コンストラクタ
cpm_LocalDomainInfo::cpm_LocalDomainInfo()
  : cpm_DomainInfo(), cpm_ActiveSubdomainInfo()
{
}

////////////////////////////////////////////////////////////////////////////////
// デストラクタ
cpm_LocalDomainInfo::~cpm_LocalDomainInfo()
{
}

////////////////////////////////////////////////////////////////////////////////
// 情報のクリア
void
cpm_LocalDomainInfo::clear()
{
  cpm_DomainInfo::clear();
  cpm_ActiveSubdomainInfo::clear();
}
