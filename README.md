# ultralight_remote_inspector

App that allows you to use Ultralight remote inspector easily. Sample project for MSVC/Visual Studio on Windows.

You fire it up and see this:

![Main window](https://user-images.githubusercontent.com/5182588/213102835-f92ff279-56ed-436f-acb1-7a7f288a8cc3.png)

Just enter your client's address and click Connect. Once you're connected, you will see a list of inspectable targets:

![After connection](https://user-images.githubusercontent.com/5182588/213103045-134f50b6-e474-43db-9c23-59cb7acf14fd.png)

Clicking "Inspect" opens up the actual inspector:

![Inspector itself](https://user-images.githubusercontent.com/5182588/213103755-1fb4e7bd-6b25-4880-ac56-5c960374e852.png)

Bonus perk is that the included redistributable inspector is bundled into just 3 files from over 1000, which was done thanks to this project: https://github.com/TFORevive/webkit-inspector-ultralight

## Building

1. Copy `ultralight` dir from Ultralight's SDK (has to have `include` and `lib` dirs inside).

2. Build the app.

3. Copy `inspector` folders next to your built app's exe (for example into `x64/Release`). Also copy `resources` folder from your Ultralight SDK to the same location. You will need to distribute them with your app too, you can optionally adjust paths in source code to use the same location as your main client app, if they differ from defaults.

4. Copy all your Ultralight DLLs next to the app's exe too.

5. Launch `inspector.exe` and connect, assuming your client is running and its inspector server is also running (see below).

## How to run inspector server

The target which you want to debug must first start the inspector server, before this app can connect to it. Like this:
```cpp
renderer_->StartRemoteInspectorServer("127.0.0.1", 19998);
```

## Limitations

* You cannot connect to more than one client in the lifetime of the app, apparently. You have to close and restart the inspector app before you can connect to a new client, which is a very annoying.

* Closing the windows in the wrong order will cause a crash.

* Hovering over HTML elements does not hover them in the actual app like a normal browser would do.

* The bundled inspector does not display some SVG icons due to a Safari bug that was already fixed somewhere in 2020, so will be fixed in Ultralight v1.4 automatically.
