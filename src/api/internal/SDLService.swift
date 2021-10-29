import WinSDK
import struct WinSDK.UINT
import Foundation
import SDLRaw

fileprivate var SDL_INIT_TIMER: UInt32 = 0x00000001
fileprivate var SDL_INIT_AUDIO: UInt32 = 0x00000010
fileprivate var SDL_INIT_VIDEO: UInt32 = 0x00000020
fileprivate var SDL_INIT_JOYSTICK: UInt32 = 0x00000200
fileprivate var SDL_INIT_HAPTIC: UInt32 = 0x00001000
fileprivate var SDL_INIT_GAMECONTROLLER: UInt32 = 0x00002000
fileprivate var SDL_INIT_EVENTS: UInt32 = 0x00004000
fileprivate var SDL_INIT_SENSOR: UInt32 = 0x00008000
fileprivate var SDL_INIT_NOPARACHUTE: UInt32 = 0x00100000


public class SDLService {
    public init() {
        InitSDL(SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS)
        sysOut(message: "SDL", with: .Verbose)

        let thread = Thread {
            var event = UnsafeMutablePointer<GameControllerEvent>(bitPattern: 0)
            while(true) {
                NextEvent(event);
            } 
        }
    }

    deinit {
    }
}

