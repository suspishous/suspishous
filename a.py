import asyncio
async def o():
    while True:
        print("sus")
        await asyncio.sleep(0)
async def main():
    while True:
        asyncio.get_event_loop().create_task(o())
        print("sus")
        await asyncio.sleep(0)
asyncio.run(main())
