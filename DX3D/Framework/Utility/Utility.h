#pragma once

namespace Utility
{
    string ToString(wstring value);
    wstring ToWString(string value);

    void Replace(OUT string& str, IN const string& comp, IN const string& rep);
    vector<string> SplitString(string origin, const string& tok, const bool& includeLast = false);

    wstring GetExtension(wstring path);
    string GetFileName(string path);
    string GetFileNameWidthoutExtension(string path);

    bool ExistDirectory(string path);
    bool ExistFile(string path);

    void CreateFolders(string path);
}