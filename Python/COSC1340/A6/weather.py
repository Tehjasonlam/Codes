def getWeatherMessage(temp,humidity,windspeed):
    weather_message = "Weather not known"
    if temp >= 64 and temp <= 75 and humidity < 50 and windspeed < 10:
        weather_message = "It is a good weather day"
    elif temp > 85 or temp < 45 or humidity > 80 or windspeed > 20:
        weather_message = "It is a bad weather day"
    else:
        weather_message = "It is just another day"
    return weather_message

itemp = int(input("What is the temperature in Fahrenheit? "))
ihumidity = int(input("What is the humidity in %? "))
iwindspeed = int(input("What is the windspeed in miles/hour? "))

print(getWeatherMessage(itemp, ihumidity, iwindspeed))

