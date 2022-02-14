# Logic guide: https://stackoverflow.com/a/1746642

wires = dict()

def main():
    with open('2015\Day7\input.txt') as input:
        lines = input.readlines()
        
        mapInputs(lines)

        signal = evalSignal('a')
        print("Part 1, wire a:", signal)

        mapInputs(lines)
        wires['b'] = str(signal)

        signal = evalSignal('a')
        print("Part 1, wire b:", signal)


def mapInputs(lines):
    for line in lines:
            line = line.strip()
            signal, wire = line.split("->")
            wires[wire.strip()] = signal.strip()
        
def evalSignal(wire):
    if str(wire).isnumeric() is False:
        signal = str(wires[wire])
        # print(signal)
        if signal.isnumeric() is False:
            if 'AND' in signal:
                leftExp, rightExp = signal.split(' AND ')
                wires[wire] = evalSignal(leftExp) & evalSignal(rightExp)
                return evalSignal(wire)
            elif 'OR' in signal:
                leftExp, rightExp = signal.split(' OR ')
                wires[wire] = evalSignal(leftExp) | evalSignal(rightExp)
                return evalSignal(wire)
            elif 'LSHIFT' in signal:
                leftExp, rightExp = signal.split(' LSHIFT ')
                wires[wire] = evalSignal(leftExp) << evalSignal(rightExp)
                return evalSignal(wire)
            elif 'RSHIFT' in signal:
                leftExp, rightExp = signal.split(' RSHIFT ')
                wires[wire] = evalSignal(leftExp) >> evalSignal(rightExp)
                return evalSignal(wire)
            elif 'NOT' in signal:
                exp = signal.replace('NOT ', '')
                wires[wire] = 65535 - evalSignal(exp)
                return evalSignal(wire)
            else:
                return evalSignal(signal)
        else:
            return int(signal)
    else:
        return int(wire)

main()
# print(123 << 2) # LeftShift
# print(123 & 456) # AND 
# print(123 | 456) # OR
# print(456 >> 2) # RightShift
        
    