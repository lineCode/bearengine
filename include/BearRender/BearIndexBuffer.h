#pragma once
namespace BearEngine
{
	class BearIndexBuffer :public BearResource
	{
	public:
		BEAR_CLASS_NO_COPY(BearIndexBuffer);
		static BearIndexBuffer* Create();
		~BearIndexBuffer();
	private:
		BearIndexBuffer();
	};
}