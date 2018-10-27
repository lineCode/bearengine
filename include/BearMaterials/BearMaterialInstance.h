#pragma once
namespace BearEngine
{
	class BEARENGINE_API BearMaterialInstance
	{
	public:
		BEAR_CLASS_NO_COPY(BearMaterialInstance);
		~BearMaterialInstance();
		virtual void set();
	protected:
		BearMaterialInstance(bsize id);
		BearMaterial*material; 
	};
};