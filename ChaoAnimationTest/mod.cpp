extern "C"
{
  __declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		WriteJump((void*)0x0075E2C0, ALBHV_RunawayFromPlayer_);
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}
