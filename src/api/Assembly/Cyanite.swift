import Foundation

public typealias FlowFunc = () -> Void


fileprivate var flows: [FlowFunc] = []


@_cdecl("AssemblyInit") func assemblyInit() {
    print("CYANITE ASSEMBLY\n")
    let flow1 = PlayerFlow()
    let flow2 = AIFlow()

}

@available(macOS 12.0, *)
@_cdecl("AssemblyUpdate") func update() {
    let playerThread = Thread {
        flows[0]()
    }
    
    let aiThread = Thread {
        flows[1]()
    }
    
    playerThread.start()
    aiThread.start()
    
    while !playerThread.isFinished || !aiThread.isFinished {
        
    }
    
    print("Assembly Frame Start")
    
    print("Assembly Frame End")

}

public func register(flow: @escaping FlowFunc) {
    flows.append(flow)
}


class Cyanite {
  init() {
  }
}
