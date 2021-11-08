import ControllerKit

public enum KeyCode {
    case W
    case S
    case A
    case D
}

public enum Axis: String {
    case MouseX = "MouseX"
    case MouseY = "MouseY"
}

public class Input {
    public func axis(with name: String) -> Float {
        return 0
    }

    public func isKeyDown(with code: KeyCode) -> Bool {
        return true
    }

    public func isKeyUp(with code: KeyCode) -> Bool {
        return true
    }

    public func isKeyPressed(with code: KeyCode) -> Bool {
        return true
    }
}
