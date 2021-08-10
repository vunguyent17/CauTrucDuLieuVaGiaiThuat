#pragma once
#include "OTo.h"
class OToHangNang: public OTo
{
public:
	OToHangNang()
	{
		Loai = 4;
		ten_loai = "O to hang nang";
		phi_qua_tram = 20000;
		thoi_gian_qua_tram = 15;
	}
};

