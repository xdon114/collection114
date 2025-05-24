from time import time as _get_time

class TimerError(Exception):
    "Exception describing bad request of Timer time"
    pass


class Timer:
    """\
Timer type for debugging.

class Timer(start = False)
    Timer type.
    The type depends on time.time().
    if *start* is True, then start th etimer when initializing.

    fn start()
        start the timer.
        if the timer is running, then do nothing.
    
    fn pause()
        pause the timer.
        if the timer is pausing, then do nothing.

    fn cur_time() -> float
        get the currunt time.
        if the timer is pausing, then raise an error.
    
    fn pause_time() -> float
        get the timer time when paused.
        if the timer is running, then raise an error.
    
    fn running() -> bool
        test if timer is running.
"""

    __slots__ = ("_start_tm",
                 "_pause_tm",
                 "_is_running",
                )
    _start_tm: float
    _pause_tm: float
    _is_running: bool
    
    def __init__(self, start: bool = False):
        tm = _get_time()
        self._start_tm = 0.0
        self._pause_tm = 0.0
        self._is_running = start
        if start:
            self._start_tm = tm
            
    def start(self):
        tm = _get_time()
        if not self._is_running:
            self._is_running = True
            self._start_tm = tm + (self._pause_tm - self._start_tm)
        
    def pause(self):
        tm = _get_time()
        if self._is_running:
            self._is_running = False
            self._pause_tm = tm
    
    def reset(self):
        self._is_running = False
        self._start_tm = 0.0
        self._pause_tm = 0.0
    
    def cur_time(self) -> float:
        "the currunt timer time\n"
        tm = _get_time()
        if self._is_running:
            return tm - self._start_tm
        raise TimerError("requesting cur_time of Timer when pausing")
    
    def pause_time(self) -> float:
        "the timer time before pause\n"
        if not(self._is_running is None or self._is_running):
            return self._pause_tm
        raise TimerError("requesting pause_time of Timer when running")
    
    def running(self) -> bool:
        "test if timer is running\n"
        return self._is_running
