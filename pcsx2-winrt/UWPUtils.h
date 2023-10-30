#pragma once

#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Pickers.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.UI.Core.h>

namespace UWP
{
	inline std::string GetLocalFolder()
	{
		using namespace winrt::Windows::Storage;
		
		try
		{
			auto externalFolderPath = L"E:\\xbsx2";
			auto externalFolderItem = StorageFolder::TryGetItemAsync(externalFolderPath).get();
			
			if (externalFolderItem) 
			{
				// E:\xbsx2 exists, return its path
				return winrt::to_string(externalFolderPath);
			}
		}
		catch (...)
		{
			
		}

		// If E:\xbsx2 doesn't exist or if there's an exception, fall back to default LocalFolder path.
		return winrt::to_string(ApplicationData::Current().LocalFolder().Path());
	}
}
