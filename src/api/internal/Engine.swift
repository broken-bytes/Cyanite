import WinSDK

var engine: Engine!


internal func createEngine(with window: HWND) {
    engine = Engine(with: window)
}

public class Engine {
    let window: HWND

    public init(with window: HWND) {
        self.window = window
        loggerInit()
        sysOut(message: "Engine initialized", with: .Verbose)
    }

    deinit {

    }
    
    func update() -> Void {

    }

}
