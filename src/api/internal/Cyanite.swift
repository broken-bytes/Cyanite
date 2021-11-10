import NativeLib
import WinSDK

@main
class Cyanite {
    static func main() -> Void { 
        dlopen("Cyanite.dll",RTLD_NOW)
        CyaniteInit { 
            CyanitePollEvent { hasEvent, event in
                if hasEvent {
                    if(event!.pointee.Type.rawValue == 5) {
                        CyaniteDeinit()
                    }
                }
            }
        }
    }
}

