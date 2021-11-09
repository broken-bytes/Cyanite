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
                    //print(event!.pointee.Type)
                }
            }
        }
    }
}

