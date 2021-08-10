#pragma once
#include "OTo.h"
class OToTrungBinh: public OTo
{
public:

	OToTrungBinh()
	{
		Loai = 2;
		ten_loai = "O to trung binh";
		phi_qua_tram = 10000;
		thoi_gian_qua_tram = 10;
	}
};

