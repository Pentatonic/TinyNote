rem last modified: 2009.6.12 by John Liu

"C:\Program Files\7-Zip\7z.exe" a -t7z "johnliu_backup_%date:~0,4%%date:~5,2%%date:~8,2%.7z" @backuplist.txt -scsWIN -mx=9
copy "D:\backup\johnliu_backup_%date:~0,4%%date:~5,2%%date:~8,2%.7z" "\\remote-server\pentatonic"

