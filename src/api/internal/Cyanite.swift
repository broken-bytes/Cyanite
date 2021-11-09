import NativeLib
import WinSDK


func update() -> Void{

}

@main
class Cyanite {
    static func main() -> Void { 
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

