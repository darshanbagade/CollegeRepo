# Smart Light Agent - Simple Reflex Agent

def smart_light_agent(outside_light, human_present):
    
    if human_present == "yes" and outside_light == "no":
        return "Light ON"
    else:
        return "Light OFF"

# Taking input from user
outside_light = input("Is outside light available? (yes/no): ").lower()
human_present = input("Is human present in the room? (yes/no): ").lower()

# Agent decision
result = smart_light_agent(outside_light, human_present)

print("Agent Decision:", result)