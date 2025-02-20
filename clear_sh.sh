#!/bin/sh

a=$(df -tH | grep disk2 | awk {'print $4'})
echo Free space before clean "\033[31m $a \033[0m "

df -h ~/
rm -rf ~/Library/Caches/*
rm -rf ~/Library/Application\ Support/Code/Cache
rm -rf ~/Library/Application\ Support/Code/CachedData
rm -rf ~/Library/Application\ Support/Code/CachedExtension
rm -rf ~/Library/Application\ Support/Code/CachedExtensions
rm -rf ~/Library/Application\ Support/Code/CachedExtensionVSIXs
rm -rf ~/Library/Application\ Support/Code/Code\ Cache
rm -rf ~/Library/Application\ Support/Code/Service\ Worker/ScriptCache
rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/ScriptCache
rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage
rm -rf ~/Library/Application\ Support/Slack/Cache
rm -rf ~/Library/Application\ Support/Slack/Code\ Cache
rm -rf ~/Library/Safari/Favicon\ Cache/
rm -rf ~/Library/Application\ Support/Telegram\ Desktop/tdata/user_data
rm -rf ~/Library/Application\ Support/Google/Chrome/Default/Service\ Worker/CacheStorage
rm -rf ~/Library/Application\ Support/Google/Chrome/Default/Service\ Worker/ScriptCache
rm -rf ~/Library/Application\ Support/Docker\ Desktop/Cache/
rm -rf ~/Library/Application\ Support/Docker\ Desktop/Code\ Cache/
rm -rf ~/Library/Developer/CoreSimulator/Caches
rm -rf ~/Library/Developer/CoreSimulator/Devices
rm -rf ~/Library/Developer/Xcode/DerivedData
rm -rf ~/Library/Application\ Support/Code/Cache

rm -rf ~/Library/Containers/com.apple.Safari/Data/Library/Caches/
rm -rf ~/Library/Application\ Support/zoom.us/AutoUpdater
rm -rf ~/Library/Application\ Support/Google/Chrome/BrowserMetrics-spare.pma
rm -rf ~/Library/Application\ Support/Google/Chrome/GrShaderCache/GPUCache/
rm -rf ~/Library/Application\ Support/Code/Service\ Worker/CacheStorage/
rm -rf ~/Library/Application\ Support/Code/Service\ Worker/ScriptCache/
rm -rf ~/Library/Application\ Support/Code/User/workspaceStorage/
rm -rf ~/Library/Application\ Support/Code/CachedExtensions/
rm -rf ~/Library/Application\ Support/Code/logs/
rm -rf ~/Library/Application\ Support/Slack/Cache/
rm -rf ~/Library/Developer/CoreSimulator/Caches/
rm -rf ~/Library/Developer/CoreSimulator/Devices/
rm -rf ~/Library/Logs/
rm -rf ~/Library/Google/GoogleSoftwareUpdate/
rm -rf ~/Library/Application\ Support/Code/CachedData/
rm -rf ~/Library/Application\ Support/Slack/logs
rm -rf ~/Library/Application\ Support/Code/CachedExtensionVSIXs/
rm -rf ~/Library/Application\ Support/Code/Code\ Cache/
rm -rf ~/Library/Application\ Support/Google/Chrome/Default/Service\ Worker/CacheStorage/
rm -rf  ~/Library/Application\ Support/Google/Chrome/Default/Service\ Worker/ScriptCache/
rm -rf ~/Library/Application\ Support/Google/Chrome/ShaderCache/GPUCache/

echo "\n\033[32;1m   ______________"
echo "   cleaning done!"
echo "\033[32;1m __________________ \033[0m\n"
b=$(df -tH | grep disk2 | awk {'print $4'})
echo "\033[0m"Free space after clean "\033[32m $b"

