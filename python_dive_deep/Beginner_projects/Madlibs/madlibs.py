

#string concatenation (how to bring or put strings together)



#following methods to build strings

# print("subscribe to " + "Rohit")
# print("subscrive to {}".format('youtuber'))
# print(f"subscrive to {'youtuber'}")

adj = input('Enter an adjective: ')
verb1  = input('Enter a verb: ')
verb2 = input('Enter another verb: ')
noun = input('enter a noun - a famous personell perhaps: ')

built_string = (
    f"Computer progarmming is so {adj}!\n"
    "It makes me excited all the time because, \n"
    f"I love to {verb1}.\n"
    f"Stay hydrated and {verb2} like you are {noun}"

)
print(built_string)
