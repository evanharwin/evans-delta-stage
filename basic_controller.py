from serial import Serial as S
import keyboard

s = S('COM3', 9600)

def act(verb: str):
    print(verb)
    s.write(verb.encode('utf-8'))

keyboard.on_press_key('w', lambda e: act('a+2000'))
keyboard.on_press_key('s', lambda e: act('a-2000'))
keyboard.on_press_key('e', lambda e: act('b+2000'))
keyboard.on_press_key('d', lambda e: act('b-2000'))
keyboard.on_press_key('r', lambda e: act('c+2000'))
keyboard.on_press_key('f', lambda e: act('c-2000'))

keyboard.wait('esc')