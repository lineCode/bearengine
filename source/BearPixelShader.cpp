#include "BearEngine.hpp"
extern BearCore::BearMap<BearCore::BearStringConteniar, BearEngine::BearMultiResource<BearEngine::BearPixelShader>>*PixelShaderMap;
BearEngine::BearPixelShader * BearEngine::BearPixelShader::Create(const bchar * name)
{
	auto item = PixelShaderMap->find(BearCore::BearStringConteniar::BearStringConteniar(name, false));
	if (item == PixelShaderMap->end())
	{

		BearPixelShader* result = BearCore::bear_new<BearPixelShader>(name);
		BearMultiResource<BearPixelShader> obj;
		obj.get()->get < BearGraphics::BearTexture2DRef>() = result->get < BearGraphics::BearTexture2DRef>();;
		BearCore::BearString::Copy(result->get_name(), 64, name);
		BearCore::BearString::Copy(obj.get()->get_name(), 64, name);
		PixelShaderMap->insert(name, obj);
		return result;
	}
	else
	{
		item->second++;
		return   *item->second.get();
	}
}

BearEngine::BearPixelShader::~BearPixelShader()
{
	auto item = PixelShaderMap->find(BearCore::BearStringConteniar::BearStringConteniar(get_name(), false));
	BEAR_ASSERT(item != PixelShaderMap->end());
	item->second--;
	if (item->second.empty())
		PixelShaderMap->erase(item);
}
static const bchar*ShaderPath = TEXT("..\\..\\content\\stalker2d\\shaders\\dx11\\");

BearEngine::BearPixelShader::BearPixelShader(const bchar * name)
{
	BearCore::BearStringPath temp1;
	BearCore::BearStringPath temp1;

	BearCore::BearString::Copy(temp1, ShaderPath);
	BearCore::BearString::Contact(temp1, name);
	BearCore::BearString::Contact(temp1, TEXT(".ps"));
	get < BearGraphics::BearPixelShaderRef>() = BearCore::bear_new<BearGraphics::BearPixelShaderRef>();
	BearCore::BearString Error;
	BEAR_ASSERT(get< BearGraphics::BearPixelShaderRef>()->compileFromFile(temp1, BearCore::BearEncoding::UTF8, Error));
}