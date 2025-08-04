import json
import random
import uuid

def create_agent():
    name = random.choice(["Ares", "Nyx", "Hermes", "Echo", "Thanatos"])
    agent_id = str(uuid.uuid4())[:8]
    agent = {"codename": name, "id": agent_id}
    with open("data/agents.json", "w") as f:
        json.dump(agent, f, indent=2)
    print(f"Agent created: {name} [{agent_id}]")