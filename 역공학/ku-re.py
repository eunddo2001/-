import sys
import frida

def on_message(message, data):
    print("[on_message] message:", message, "data:", data)


def main(target_process, script_text):
    print("[*] Inspecting file operations")

    session = frida.attach(target_process)

    script = session.create_script(script_text)
    script.on("message", on_message)
    script.load()

    print("[!] Ctrl+C to detach from the instrumented program.\n\n")
    sys.stdin.read()
    session.detach()


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: %s <process name or PID>" % __file__)
        sys.exit(1)

    try:
        target_process = int(sys.argv[1])
    except ValueError:
        target_process = sys.argv[1]
    
    script_text = ''
    with open(sys.argv[2], 'r') as fd:
        script_text += fd.read() + '\n'

    main(target_process, script_text)