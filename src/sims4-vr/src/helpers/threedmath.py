import math

class Pos:
  def __init__(self, x, y, z):
    self.x = x
    self.y = y
    self.z = z

def multiplicationLineColumn(line,column):
    try:
        sizeLine=len(line)
        sizeColumn=len(column)
        if(sizeLine!=sizeColumn):
            raise ValueError("Exception")
        res = sum([line[i] * column[i] for i in range(sizeLine)])
        return res
    except ValueError:
        print("sould have the same len line & column")

def  getColumn(matrix,numColumn):
    size=len(matrix)
    column= [matrix[i][numColumn] for i in range(size)]
    return column

def getLine(matrix,numLine):
    line = matrix[numLine]
    return line

def mdot(A, B):
    result_matrix=[]
    for i in range(len(A)):
        result_matrix.append([])
        for j in range(len(B)):
            result_matrix[i].append(multiplicationLineColumn(getLine(A,i),getColumn(B,j)))
    return result_matrix

def py_euler_to_rotmat(yaw, pitch, roll):
    Rz_yaw = [
        [math.cos(yaw), -math.sin(yaw), 0],
        [math.sin(yaw),  math.cos(yaw), 0],
        [            0,              0, 1]]
    Ry_pitch = [
        [ math.cos(pitch), 0, math.sin(pitch)],
        [               0, 1,               0],
        [-math.sin(pitch), 0, math.cos(pitch)]]
    Rx_roll = [
        [1,              0,               0],
        [0, math.cos(roll), -math.sin(roll)],
        [0, math.sin(roll),  math.cos(roll)]]
    # R = RzRyRx
    rotMat = mdot(Rz_yaw, mdot(Ry_pitch, Rx_roll)) #Original
    #rotMat = mdot(Rx_roll, mdot(Ry_pitch, Rz_yaw))#test
    #rotMat = mdot(Rx_roll, mdot(Rz_yaw, Ry_pitch))#test
    #rotMat = mdot(mdot(Rz_yaw, Ry_pitch), Rx_roll)#test 13 dec
    return rotMat

def euler2quat(ai, aj, ak, axes='sxyz'):
    """Return `quaternion` from Euler angles and axis sequence `axes`
    Parameters
    ----------
    ai : float
        First rotation angle (according to `axes`).
    aj : float
        Second rotation angle (according to `axes`).
    ak : float
        Third rotation angle (according to `axes`).
    axes : str, optional
        Axis specification; one of 24 axis sequences as string or encoded
        tuple - e.g. ``sxyz`` (the default).
    Returns
    -------
    quat : array shape (4,)
       Quaternion in w, x, y z (real, then vector) format
    Examples
    --------
    >>> q = euler2quat(1, 2, 3, 'ryxz')
    >>> np.allclose(q, [0.435953, 0.310622, -0.718287, 0.444435])
    True
    """
    #axes: syzx
    firstaxis = 1
    parity = 0
    repetition = 0
    frame = 0
    _NEXT_AXIS = [1, 2, 0, 1]

    i = firstaxis + 1
    j = _NEXT_AXIS[i+parity-1] + 1
    k = _NEXT_AXIS[i-parity] + 1

    if frame:
        ai, ak = ak, ai
    if parity:
        aj = -aj

    ai /= 2.0
    aj /= 2.0
    ak /= 2.0
    ci = math.cos(ai)
    si = math.sin(ai)
    cj = math.cos(aj)
    sj = math.sin(aj)
    ck = math.cos(ak)
    sk = math.sin(ak)
    cc = ci*ck
    cs = ci*sk
    sc = si*ck
    ss = si*sk

    q = [0,0,0,0]
    if repetition:
        q[0] = cj*(cc - ss)
        q[i] = cj*(cs + sc)
        q[j] = sj*(cc + ss)
        q[k] = sj*(cs - sc)
    else:
        q[0] = cj*cc + sj*ss
        q[i] = cj*sc - sj*cs
        q[j] = cj*ss + sj*cc
        q[k] = cj*cs - sj*sc
    if parity:
        q[j] *= -1.0

    return q

def qmult(q1, q2):
    ''' Multiply two quaternions
    Parameters
    ----------
    q1 : 4 element sequence
    q2 : 4 element sequence
    Returns
    -------
    q12 : shape (4,) array
    Notes
    -----
    See : http://en.wikipedia.org/wiki/Quaternions#Hamilton_product
    '''
    w1, x1, y1, z1 = q1
    w2, x2, y2, z2 = q2
    w = w1*w2 - x1*x2 - y1*y2 - z1*z2
    x = w1*x2 + x1*w2 + y1*z2 - z1*y2
    y = w1*y2 + y1*w2 + z1*x2 - x1*z2
    z = w1*z2 + z1*w2 + x1*y2 - y1*x2
    return [w, x, y, z]

def quat2mat(q):
    ''' Calculate rotation matrix corresponding to quaternion
    Parameters
    ----------
    q : 4 element array-like
    Returns
    -------
    M : (3,3) array
      Rotation matrix corresponding to input quaternion *q*
    Notes
    -----
    Rotation matrix applies to column vectors, and is applied to the
    left of coordinate vectors.  The algorithm here allows quaternions that
    have not been normalized.
    References
    ----------
    Algorithm from http://en.wikipedia.org/wiki/Rotation_matrix#Quaternion
    Examples
    --------
    >>> import numpy as np
    >>> M = quat2mat([1, 0, 0, 0]) # Identity quaternion
    >>> np.allclose(M, np.eye(3))
    True
    >>> M = quat2mat([0, 1, 0, 0]) # 180 degree rotn around axis 0
    >>> np.allclose(M, np.diag([1, -1, -1]))
    True
    '''
    w, x, y, z = q
    Nq = w*w + x*x + y*y + z*z
    if Nq < 2.220446049250313e-16:
        return([[1, 0, 0],[0, 1, 0],[0, 0, 1]])
    s = 2.0/Nq
    X = x*s
    Y = y*s
    Z = z*s
    wX = w*X; wY = w*Y; wZ = w*Z
    xX = x*X; xY = x*Y; xZ = x*Z
    yY = y*Y; yZ = y*Z; zZ = z*Z
    return(
           [[ 1.0-(yY+zZ), xY-wZ, xZ+wY ],
            [ xY+wZ, 1.0-(xX+zZ), yZ-wX ],
            [ xZ-wY, yZ+wX, 1.0-(xX+yY) ]])


#tpy_rotmat_to_euler this might be wrong since i verifed it against a version of py_euler_to_rotmat that seams to malfunction at certain times(ie some type of gimbal lock)
def tpy_rotmat_to_euler(M):
    _EPS4=1e-6
    
    #axes: syzx
    firstaxis = 1
    parity = 0
    repetition = 0
    frame = 0
    _NEXT_AXIS = [1, 2, 0, 1]
    
    i = firstaxis
    j = _NEXT_AXIS[i+parity]
    k = _NEXT_AXIS[i-parity+1]
    
    if repetition:
        sy = math.sqrt(M[i][j]*M[i][j] + M[i][k]*M[i][k])
        if sy > _EPS4:
            ax = math.atan2( M[i][j],  M[i][k])
            ay = math.atan2( sy,       M[i][i])
            az = math.atan2( M[j][i], -M[k][i])
        else:
            ax = math.atan2(-M[j][k],  M[j][j])
            ay = math.atan2( sy,       M[i][i])
            az = 0.0
    else:
        cy = math.sqrt(M[i][i]*M[i][i] + M[j][i]*M[j][i])
        if cy > _EPS4:
            ax = math.atan2( M[k][j],  M[k][k])
            ay = math.atan2(-M[k][i],  cy)
            az = math.atan2( M[j][i],  M[i][i])
        else:
            ax = math.atan2(-M[j][k],  M[j][j])
            ay = math.atan2(-M[k][i],  cy)
            az = 0.0
    if parity:
        ax, ay, az = -ax, -ay, -az
    if frame:
        ax, az = az, ax
    return Pos(math.degrees(ay), math.degrees(ax), math.degrees(az))#switch the axles here,is it right? Dont know, if it wors, it works...???

def py_rotmat_to_euler(R):

    sy = math.sqrt(R[0][0] * R[0][0] +  R[1][0] * R[1][0])
    singular = sy < 1e-6
    if not singular:
        x = math.atan2(R[2][1] , R[2][2])
        y = math.atan2(-R[2][0], sy)
        z = math.atan2(R[1][0], R[0][0])
    else:
        x = math.atan2(-R[1][2], R[1][1])
        y = math.atan2(-R[2][0], sy)
        z = 0
    return Pos(math.degrees(x),math.degrees(y),math.degrees(z))
