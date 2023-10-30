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
			
			// Get the StorageFolder for the drive
			auto storageFolder = StorageFolder::GetFolderFromPathAsync(externalFolderPath).get();

			// Check if the folder exists on the drive
			if (storageFolder) 
			{
				// E:\xbsx2 exists, return its path
				return winrt::to_string(externalFolderPath);
			}
		}
		catch (const winrt::hresult_error& ex)
		{
			// Handle specific error (ex.message() contains the error message)
			// For now, we'll just ignore the exception and proceed to the fallback path.
		}

		// If E:\xbsx2 doesn't exist or if there's an exception, fall back to default LocalFolder path.
		return winrt::to_string(Windows::Storage::ApplicationData::Current().LocalFolder().Path());
	}
}