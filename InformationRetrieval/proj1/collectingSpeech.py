import speech_recognition as sr


def Houndify_collect():
    # obtain audio from the microphone
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Say something!")
        audio = r.listen(source)


    # Houndify client IDs are Base64-encoded strings
    HOUNDIFY_CLIENT_ID = "p_iiwPUKu5p7REusKvEUxQ=="
    # Houndify client keys are Base64-encoded strings
    HOUNDIFY_CLIENT_KEY = "GJEk4t51HxlTKXCmaC_wjTikG0f8KcoJTH8g0Koyc9wfMu5WEwo2IEAn0Yj_Zbhwr64DOiPEH1V_y24gVSpHog=="
    res  = r.recognize_houndify(audio, client_id=HOUNDIFY_CLIENT_ID, client_key=HOUNDIFY_CLIENT_KEY)
        
    return res
