def check_inventory(inventory, low):
  d = []
  for i in inventory.keys():
    if (inventory[i] < low):
      d.append(i)
  return d

inventory = {'ibuprofen':800,'tylenol':366,'advil':75}
print(check_inventory(inventory, 100))
print(check_inventory(inventory, 400))


def CI2(inventory, low):
    d = []
    for i in inventory.keys():
        if (inventory[i] < low):
            d.append(i)
    d.sort()
    return d

inventory = {'ibuprofen':800,'tylenol':366,'advil':75}
print(CI2(inventory, 100))
print(CI2(inventory, 400))