def rule1(symptoms):
    if 'fever'  in symptoms and 'cough'  in symptoms and 'fatigue'  in symptoms:
        return 'You may have flu'
    return None


def rule2(symptoms):
    if 'fever'  in symptoms and 'rash'  in symptoms and 'headache'  in symptoms:
        return 'You may have meningitis'
    return None


def rule3(symptoms):
    if 'pain'  in symptoms and 'swelling'  in symptoms and 'bruising'  in symptoms:
        return 'You may have a fracture'
    return None


def rule4(symptoms):
    if 'abdominal pain'  in symptoms and 'diarrhea'  in symptoms and 'nausea'  in symptoms:
        return 'You may have food poisoning'
    return None


def rule5(symptoms):
    if 'shortness of breath'  in symptoms and 'chest pain'  in symptoms and 'dizziness'  in symptoms:
        return 'You may be having a heart attack. Please seek medical attention immediately'
    return None

def rule6(symptoms):
    if 'sore throat'  in symptoms and 'runny nose'  in symptoms and 'sneezing'  in symptoms:
        return "You may have a cold"
    return None

def rule7(symptoms):
    if 'muscle aches'  in symptoms and 'chills'  in symptoms and 'sweating'  in symptoms:
        return "You may have the flu"
    return None

def rule8(symptoms):
    if 'itching'  in symptoms and 'redness'  in symptoms and 'swelling'  in symptoms:
        return "You may have an allergic reaction"
    return None

def rule9(symptoms):
    if 'abdominal pain'  in symptoms and 'bloating'  in symptoms and 'gas'  in symptoms:
        return "You may have irritable bowel syndrome (IBS)"
    return None

def rule10(symptoms):
    if 'confusion'  in symptoms and 'memory loss'  in symptoms and 'difficulty speaking'  in symptoms:
        return "You may be experiencing a neurological disorder"
    return None


def diagnose(symptoms):
    rules = [rule1, rule2, rule3, rule4, rule5,rule6,rule7,rule8,rule9,rule10]
    results = []
    for rule in rules:
        result = rule(symptoms)
        if result:
            results.append(result)
    if len(results) == 0:
        return 'Sorry, we could not diagnose your condition.'
    elif len(results) == 1:
        return results[0]
    else:
        return 'You may have multiple conditions: ' + ', '.join(results)


symptoms = []

while(True):
    print()
    print("1. Press 0 to add more symptoms.")
    print("2. Press 1 to end.")
    n=int(input("Enter option number: "))
    print()
    if(n==1):
        break

    a=input("Enter Symptom: ")
    symptoms.append(a)

result = diagnose(symptoms)
print(result)
