//#pragma warning(push)
//#pragma warning(disable:4838)

#include "stdafx.h"
#include "chao.h"

signed int __cdecl ALBHV_RunawayFromPlayer_(ObjectMaster* a1)
{
	ChaoData1 *v1; // esi
	ChaoData2 *v2; // ebx
	signed int v3; // ecx
	float v4; // ST10_4
	unsigned __int16 v6; // [esp-3h] [ebp-14h]

	v1 = a1->Data1;
	v2 = a1->Data2;
	AL_ParameterGetSkill(a1, v6);
	if (!v1->Behavior.Mode)
	{
		if ((double)rand() * 0.000030517578 >= 0.5)
			if (v3 >= 0.2)
			{
				if (v3 >= 0.60000002)
				{
					AL_SetMotionLink(a1, 106);
				}
				else
				{
					AL_SetMotionLink(a1, 119);
				}
			}
			else
			{
				AL_SetMotionLink(a1, 118);
			}
		AL_FaceSetEye(a1, 1);
		if ((double)rand() * 0.000030517578 >= 0.40000001)
		{
			AL_FaceSetMouth(a1, 8);
		}
		else
		{
			AL_FaceSetMouth(a1, 4);
		}
		AL_IconSet(a1, 5, 500);
		sub_75E180(a1);
		++v1->Behavior.Mode;
		v1->Behavior.Timer = 0;
		v1->Behavior.SubTimer = 0;
	}
	if (AL_IsEmotionTimerReset(a1))
	{
		AL_EmotionAdd(a1, EM_ST_TIRE, ChaoGlobal.ParamAddTireRun);
	}
	v3 = v1->Behavior.Timer;
	v1->Behavior.Timer = v3 + 1;
	if (v3 > 1000)
	{
		return 1;
	}
	if (!((v3 + 1) % 100) && (double)rand() * 0.000030517578 < 0.029999999)
	{
		AL_SetBehavior(a1, ALBHV_Koke);
	}
	if (AL_Dist2FromAim(a1) >= 64.0)
	{
		goto LABEL_15;
	}
	if (MOV_Dist2FromPlayer(a1, 0) >= 2500.0)
	{
		return 1;
	}
	v1->Behavior.Mode = 0;
LABEL_15:
	if (v2->MoveWork.Flag & 0x4000)
	{
		v1->Behavior.Mode = 0;
	}
	MOV_TurnToAim2(a1, 288);
	if (v2->MoveWork.Flag & 0x400)
	{
		v2->MoveWork.Acc.x = njSin(v1->entity.Rotation.y) * ChaoGlobal.RunAcc;
		v2->MoveWork.Acc.z = njCos(v1->entity.Rotation.y) * ChaoGlobal.RunAcc;
	}
	v4 = njScalor(&v2->MoveWork.Velo) * 8.0;
	AL_SetMotionSpd(a1, v4);
	return 0;
}

