#pragma once
#ifndef _Z_RENDER_TEXTURE_RESOURCE_H_
#define _Z_RENDER_TEXTURE_RESOURCE_H_

#include "DxRenderCommon.h"
#include "DxZRenderDLLDefine.h"
#include <D3D11.h>

namespace zRender
{
	class TextureResource
	{
	public:
		TextureResource();
		~TextureResource();

		int create(ID3D11Device* device, int width, int height, DXGI_FORMAT dxgifmt, TEXTURE_USAGE usage, bool bShared, const char* initData, int dataLen, int pitch);
		int open(HANDLE sharedHandle);
		void release();
		ID3D11Texture2D* getTexture() const { return m_texture; }

		bool valid() const { return m_texture != NULL; }
		int width() const { return m_width; }
		int height() const { return m_height; }
		DXGI_FORMAT pixfmt() const { return m_dxgifmt; }
		TEXTURE_USAGE usage() const { return m_usage; }

		int createResourceView();
		void releaseResourceView();
		ID3D11ShaderResourceView* getResourceView() const { return m_rsv; }

		int copyResource(const TextureResource* res);
		int update(const unsigned char* pData, int dataLen, int dataPitch, int width, int height,
			const RECT& regionUpdated);

		bool isShared() const { return m_bShared; }
		HANDLE getSharedHandle() const { return m_sharedHandle; }
	private:
		ID3D11Texture2D*			m_texture;
		ID3D11ShaderResourceView*	m_rsv;
		int m_width;
		int m_height;
		DXGI_FORMAT m_dxgifmt;
		TEXTURE_USAGE m_usage;
		bool m_bShared;
		HANDLE m_sharedHandle;

		ID3D11Device* m_device;
		ID3D11DeviceContext* m_contex;
	};
}

#endif //_Z_RENDER_TEXTURE_RESOURCE_H_